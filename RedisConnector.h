
#ifndef	__REDIS_CONNECTOR_H__

#define	__REDIS_CONNECTOR_H__


#include <stdlib.h>
#include <string.h>

#include "hiredis.h"			/* hiredis connector */


typedef	char* KeyType;			/* Temporary */
typedef	char* NodeType;			/* Temporary */
typedef	char* HostnameType;		/* Temporary */

class	RedisConnector
{
public:
    RedisConnector();
    RedisConnector(HostnameType hostname);
    ~RedisConnector();
    
    int		Connect(HostnameType hostname);
    void	Disconnect();
    
    NodeType	GetNode(KeyType key);
	int 		SetNode(KeyType key, NodeType node);
	int			DeleteKey(KeyType key);
private:
    int			_connected;	/* 0 - disconnected, 1 - connected */
    redisContext	*_context;

};

#endif

