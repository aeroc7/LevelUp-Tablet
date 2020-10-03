cmake_minimum_required(VERSION 3.0)

project(tablet)

include(${CMAKE_CURRENT_LIST_DIR}/libutils/CMakeLists.txt)

set(DEP_INCLUDES
	${DEP_INCLUDES}
	${CMAKE_CURRENT_LIST_DIR}/deps
	${CMAKE_CURRENT_LIST_DIR}/deps/include/
	${CMAKE_CURRENT_LIST_DIR}/deps/include/pixman-1
	)
	
set(DEP_LIBS
	${DEP_LIBS}
	${CMAKE_CURRENT_LIST_DIR}/deps/libcurl.a
	${CMAKE_CURRENT_LIST_DIR}/deps/libmbedtls.a
	${CMAKE_CURRENT_LIST_DIR}/deps/libz.a
	${CMAKE_CURRENT_LIST_DIR}/deps/libssl.a
	${CMAKE_CURRENT_LIST_DIR}/deps/libcrypto.a
	${CMAKE_CURRENT_LIST_DIR}/deps/libfreetype.a
	${CMAKE_CURRENT_LIST_DIR}/deps/lib/libpixman-1.a
	${CMAKE_CURRENT_LIST_DIR}/deps/lib/libcairo.a
	)

set(DEP_POST_LIBS
	${DEP_POST_LIBS}
	${CMAKE_CURRENT_LIST_DIR}/deps/libGLEW.a
	)

include(${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt)
