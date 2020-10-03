include(${CMAKE_CURRENT_LIST_DIR}/tablet/CMakeLists.txt)

set(SRC
	${SRC}
	${CMAKE_CURRENT_LIST_DIR}/xplane.cpp
	)

set(ALL_SRC ${SRC} ${HDR})

list(SORT ALL_SRC) #we're just so fancy aren't we 0w0

add_library(tablet SHARED ${DEP_LIBS} ${ALL_SRC})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -W -Wall -Werror -Wextra --std=c++14 -Wno-unused-local-typedefs \
	-Wno-missing-field-initializers -Wno-unused-parameter -Wno-unused-variable -Wno-unused-result -fPIC -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Werror -Wextra --std=c11 -Wno-unused-local-typedefs -Wno-missing-field-initializers -Wno-unused-parameter")

include_directories(tablet PUBLIC
	${DEP_INCLUDES}
    	"deps/SDK/CHeaders/XPLM"
    	"deps/SDK/CHeaders/Widgets"
    	"deps/SDK/CHeaders/Wrappers"
	)

add_definitions(-DXPLM200=1 -DXPLM210=1 -DXPLM300=1 -DXPLM301=1)
if(WIN32)
	add_definitions(-DAPL=0 -DIBM=1 -DLIN=0)
elseif(APPLE)
	add_definitions(-DAPL=1 -DIBM=0 -DLIN=0)
else()
	add_definitions(-DAPL=0 -DIBM=0 -DLIN=1)
endif()

if(UNIX)
	
	target_link_libraries(tablet
		${DEP_POST_LIBS}
		-static-libgcc
		-static-libstdc++
		-fPIC
		GL
		)
endif()

set_target_properties(tablet PROPERTIES PREFIX "")
set_target_properties(tablet PROPERTIES SUFFIX "")
set_target_properties(tablet PROPERTIES OUTPUT_NAME
	"LevelUp.xpl")

if(UNIX)
	set_target_properties(tablet PROPERTIES
	    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../../Apps/X-Plane 11/Aircraft/Extra Aircraft/levelup-737/plugins/LevelUp/lin_x64" )
    	set_target_properties(tablet PROPERTIES
	    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../../Apps/X-Plane 11/Aircraft/Extra Aircraft/levelup-737/plugins/LevelUp/lin_x64" )
endif()
