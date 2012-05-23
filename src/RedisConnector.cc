/*	RedisConnector.cc: redis connection and interaction stuff
	Copyright (C) 2012 Bereznikov Alexey

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.	*/


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
