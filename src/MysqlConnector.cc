/*	MysqlConnector.cc: contains stuff for interaction with mysql server
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

#include "MysqlConnector.h"

MysqlConnector::MysqlConnector()
{
	_driver = sql::mysql::get_driver_instance();
}

MysqlConnector::~MysqlConnector()
{
	Disconnect();
}

bool MysqlConnector::Connect(char *host, char *user, char *pass, char *db)
{
	_connection = _driver->connect(host, user, pass);
	if (_connection == NULL)
		return false;
	return true;
}

void MysqlConnector::Disconnect()
{
	if (_connection != NULL)
		delete _connection;
}

bool MysqlConnector::Execute(char *query)
{
	if (_connection == NULL)
		return false;
	sql::Statement *stmt = _connection->createStatement();
	if (stmt == NULL)
		return false;
	stmt->execute(query);
	delete stmt;
	return true;
}

sql::ResultSet MysqlConnector::ExecuteQuery(char *query)
{
	sql::Statement *stmt = _connection->createStatement();
	sql::ResultSet res = stmt->executeQuery(query);
	delete stmt;
	return res;
}