/*	MultiNode.h: contains declaration of class working with multiple nodes (i.e. in case of replication)
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


#ifndef __MULTI_NODE_H__

#define __MULTI_NODE_H__

#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

#include "Node.h"



/* Class describing single node structure */
class MultiNode : public Node
{
public:
	MultiNode();
	MultiNode(char *source);
	~MultiNode();
	
	/* mysql process command routine */
	MYSQL_RESULT	ProcessCommand(char *command);	
	
	
	/* Getting type of node */
	NodeType	GetType()	{ return NODE_TYPE_MULTI; };
	/* Getting string representation of node */
	char 		*ToString();
	/* Parsing node info from string */
	int 		FromString(char *source);
	
	
private:
	Node 	*_nodes;
	int		_count;
};



#endif
