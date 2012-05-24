/*	Node.h: contains basic declarations required to work with mysql nodes
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


#ifndef __NODE_H__

#define __NODE_H__

#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

/* Node Types */
typedef enum {NODE_TYPE_SINGLE, NODE_TYPE_MULTI} NodeType;

/* Temporary */
typedef char* MYSQL_RESULT;

/* Abstract class describing node structure */
class Node
{
public:
	Node() {};
	Node(char*) {};
	virtual ~Node() {};
	
	/* mysql process command routine */
	virtual MYSQL_RESULT	ProcessCommand(char *command) {};	
	
	
	/* Getting type of node */
	virtual NodeType	GetType() {};
	/* Getting string representation of node */
	virtual char 		*ToString() {};
	/* Parsing node info from string */
	virtual int 		FromString(char *source) {};
	
	
private:
	
};



#endif
