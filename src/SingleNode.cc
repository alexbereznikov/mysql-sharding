
#ifdef USE_PRAGMA_INTERFACE
#pragma interface			/* gcc class implementation */
#endif

#include <stdlib.h>
#include <string.h>

#include "SingleNode.h"

SingleNode::SingleNode()
{
	_address = NULL;
}

SingleNode::SingleNode(char *source)
{
	FromString(source);
}

SingleNode::~SingleNode()
{
	
}

MYSQL_RESULT	SingleNode::ProcessCommand(char *command)
{
	return	(MYSQL_RESULT)NULL;	/* TEMPORARY */
}

char	*SingleNode::ToString()
{
	if (_address == NULL)
		return	NULL;
	char	*temp = (char*)calloc(strlen(_address) + 1, 1);
	strncpy(temp, _address, strlen(_address));
	return	temp;
}

int		SingleNode::FromString(char *source)
{
	/*  TODO: add some checks */
	_address = (char*)calloc(strlen(source) + 1, 1);
	strncpy(_address, source, strlen(source));
	return	1;
}
