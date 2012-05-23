/*	RedisConnector.h: contains declarations required to interact with redis server
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


#ifndef	__REDIS_CONNECTOR_H__

#define	__REDIS_CONNECTOR_H__

#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

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

