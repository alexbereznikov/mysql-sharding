# Copyright (c) 2006, 2010, Oracle and/or its affiliates. All rights reserved.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

# Finding hiredis library
FIND_PATH(HIREDIS_INCLUDE_DIR hiredis/hiredis.h)
	    
# Including hiredis library
IF (HIREDIS_INCLUDE_DIR)
    INCLUDE_DIRECTORIES("${HIREDIS_INCLUDE_DIR}/hiredis")
ELSEIF()
    MESSAGE(FATAL_ERROR "libhiredis was not found")
ENDIF()

# INCLUDE_DIRECTORIES(/usr/local/include/hiredis)

SET(SHARDING_PLUGIN_DYNAMIC "ha_sharding")
SET(SHARDING_SOURCES src/ha_sharding.cc src/ha_sharding.h src/RedisConnector.cc src/RedisConnector.h)
MYSQL_ADD_PLUGIN(sharding ${SHARDING_SOURCES} STORAGE_ENGINE MODULE_ONLY LINK_LIBRARIES hiredis)
