
#ifndef __SINGLE_NODE_H__

#define __SINGLE_NODE_H__

#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

#include "Node.h"



/* Class describing single node structure */
class SingleNode : public Node
{
public:
	SingleNode();
	SingleNode(char *source);
	~SingleNode();
	
	/* mysql process command routine */
	MYSQL_RESULT	ProcessCommand(char *command);	
	
	
	/* Getting type of node */
	NodeType	GetType()	{ return NODE_TYPE_SINGLE; };
	/* Getting string representation of node */
	char 		*ToString();
	/* Parsing node info from string */
	int 		FromString(char *source);
	
	
private:
	char	*_address;
};



#endif
