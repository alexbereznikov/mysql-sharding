/*	MysqlConnector.h: contains stuff for interaction with mysql server
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

#ifndef __MYSQL_CONNECTOR_H__
#define __MYSQL_CONNECTOR_H__

#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

#include <driver/mysql_public_iface/.h>	/* mysql interface */

class MysqlConnector
{
public:
	MysqlConnector();
	~MysqlConnector();
	
	bool Connect(char *host, char *user, char *pass, char *db);
	void Disconnect();
	
	bool Execute(char *query);
	sql::ResultSet ExecuteQuery(char *query);
	
private:
	sql::Driver *_driver;
	sql::Connection *_connection;
};

#endif	/* __MYSQL_CONNECTOR_H__ */