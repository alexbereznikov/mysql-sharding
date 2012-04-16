
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
