/*	Logger.cc: contains implementation of logger methods
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



#include "Logger.h"

Logger::Logger(char *path)
{
	f = fopen(path, "w+");
}

Logger::~Logger()
{
    fclose(f);
}

void	Logger::Log(char *message)
{
	fprintf(f, "%s\n", message);
	fflush(f);
}
