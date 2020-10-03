include(${CMAKE_CURRENT_LIST_DIR}/gui/CMakeLists.txt)

set(SRC
	${SRC}
	${CMAKE_CURRENT_LIST_DIR}/sys_init.cpp
	)
	
set(HDR
	${HDR}
	${CMAKE_CURRENT_LIST_DIR}/sys_init.h
	)
