# CMakeLists.txt: make file for sharding engine
# Copyright (C) 2012 Bereznikov Alexey
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Finding hiredis library
FIND_PATH(HIREDIS_INCLUDE_DIR hiredis/hiredis.h)
	    
# Including hiredis library
IF (HIREDIS_INCLUDE_DIR)
    INCLUDE_DIRECTORIES("${HIREDIS_INCLUDE_DIR}/hiredis")
ELSEIF()
    MESSAGE(FATAL_ERROR "libhiredis was not found")
ENDIF()

# mysql plugin stuff
SET(SHARDING_PLUGIN_DYNAMIC "ha_sharding")
SET(SHARDING_SOURCES src/ha_sharding.cc src/ha_sharding.h src/RedisConnector.cc src/RedisConnector.h)
MYSQL_ADD_PLUGIN(sharding ${SHARDING_SOURCES} STORAGE_ENGINE MODULE_ONLY LINK_LIBRARIES hiredis)
