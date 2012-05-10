
#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

#include "RedisConnector.h"

RedisConnector::RedisConnector()
{
	_context = NULL;
    _connected = 0;	// We are disconnected
}

RedisConnector::RedisConnector(HostnameType hostname)
{
	_context = NULL;
    Connect(hostname);	// trying to connect
}

RedisConnector::~RedisConnector()
{
    Disconnect();	// Trying to disconnect
}

int	RedisConnector::Connect(HostnameType hostname)
{
    Disconnect();
    /* TODO: make possible to change timeout */
    struct timeval timeout = { 1, 500000 }; /* 1.5 seconds */
    /*	hostname - host to which we want to connect
     * 6379 - port to connect
     * timeout - struct which describes desired timeout
     */
    _context = redisConnectWithTimeout(hostname, 6379, timeout);
    if (_context->err)
    {
		_context = NULL;
		_connected = 0;
		return	0;		/* couldn't connect */
    }
	return	1;	/* Connected successfully */
}

void	RedisConnector::Disconnect()
{
    if (!_connected)
		return;
	if (_context == NULL)
		return;
	redisFree(_context);
}

Node	RedisConnector::GetNode(KeyType key)
{
	/* Send command and get a reply */
    redisReply	*reply = (redisReply*)redisCommand(_context, "GET %s", key);
	/* Check whether there was an error */
	if (reply == NULL)
	{
		/* There was an error */
		return	0;
	}
	/* Extract node information from reply */
	Node node(reply->str);
	/* Free reply object */
	freeReplyObject(reply);
	/* And return node information */
	return	node;
}

int	RedisConnector::SetNode(KeyType key, Node node)
{
	/* Send command and get a reply */
    redisReply	*reply = (redisReply*)redisCommand(_context, "SET %s %s", key, node.ToString());
	/* Check whether there was an error */
	if (reply == NULL)
	{
		/* There was an error */
		return	0;
	}
	freeReplyObject(reply);
	return	1;
}

int	RedisConnector::DeleteKey(KeyType key)
{
	/* Send command and get a reply */
    redisReply	*reply = (redisReply*)redisCommand(_context, "DEL %s", key);
	/* Check whether there was an error */
	if (reply == NULL)
	{
		/* There was an error */
		return	0;
	}
	freeReplyObject(reply);
	return	1;
}
