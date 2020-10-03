include(${CMAKE_CURRENT_LIST_DIR}/components/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/pages/CMakeLists.txt)
set(SRC
	${SRC}
    ${CMAKE_CURRENT_LIST_DIR}/gui_main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/gui_brains.cpp
	)
	
set(HDR
	${HDR}
    ${CMAKE_CURRENT_LIST_DIR}/gui_main.h
    ${CMAKE_CURRENT_LIST_DIR}/gui_brains.h
    ${CMAKE_CURRENT_LIST_DIR}/gui_colors.h
	)