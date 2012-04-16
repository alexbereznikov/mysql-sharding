
#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

#include <stdlib.h>
#include <string.h>

#include "MultiNode.h"

/* TODO: think about multi node structure */

MultiNode::MultiNode()
{
	
}

MultiNode::~MultiNode()
{
	
}

MYSQL_RESULT	MultiNode::ProcessCommand(char *command)
{
	return	(MYSQL_RESULT)NULL;	/* TEMPORARY */
}

char	*MultiNode::ToString()
{
	return	NULL;
}

int		MultiNode::FromString(char *source)
{
	return	0;
}
