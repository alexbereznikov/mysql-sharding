
#ifndef	__REDIS_CONNECTOR_H__

#define	__REDIS_CONNECTOR_H__


#include <stdlib.h>
#include <string.h>

#include <hiredis/hiredis.h>			/* hiredis connector */
#include "MultiNode.h"
#include "SingleNode.h"


typedef	char* KeyType;			/* Temporary */
typedef	char* HostnameType;		/* Temporary */

class	RedisConnector
{
public:
    RedisConnector();
    RedisConnector(HostnameType hostname);
    ~RedisConnector();
    
    int		Connect(HostnameType hostname);
    void	Disconnect();
    
    Node		GetNode(KeyType key);
	int 		SetNode(KeyType key, Node node);
	int			DeleteKey(KeyType key);
private:
    int			_connected;	/* 0 - disconnected, 1 - connected */
    redisContext	*_context;

};

#endif

