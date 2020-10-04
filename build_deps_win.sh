function build_deps_win()
{
	echo "Building Dependencies..."
	sleep 1.5

	mkdir $PWD/deps
	mkdir $PWD/temp_dls

	BUILD_FIN_DIR=$PWD/deps

	cd temp_dls

	#echo "Building zlib..."
	#sleep 1.5
	#git clone --recursive "https://github.com/madler/zlib.git"
	#cd zlib
	#cmake -DCMAKE_BUILD_TYPE=Release .
	#make
	
	#cp $PWD/libzlibstatic.a $BUILD_FIN_DIR/

	#cd ../

	#echo "Building mbedtls..."
	#sleep 1.5
	#git clone --recursive "https://github.com/ARMmbed/mbedtls.git"
	#cd mbedtls
	#make WINDOWS=1

	#install it
	#cp $PWD/library/libmbedtls.a $BUILD_FIN_DIR/

	#cd ../

	#echo "Building OpenSSL..."
	#sleep 1.5
	#wget -O osslz "https://github.com/openssl/openssl/archive/OpenSSL_1_1_1h.zip"
	#unzip osslz -d openssl
	#cd openssl/openssl-OpenSSL_1_1_1h
	#./config
	#make

	#install it
	#cp $PWD/libcrypto.a $BUILD_FIN_DIR/
	#cp $PWD/libssl.a $BUILD_FIN_DIR/

	#cd ../..
	
	#echo "Building cUrl..."
	#sleep 1.5
	#git clone --recursive "https://github.com/curl/curl.git"
	#cd curl
	#./buildconf
	#./configure --prefix=$PWD --with-ssl=$BUILD_FIN_DIR --without-nghttp2 --with-mbedtls=$BUILD_FIN_DIR --with-zlib=$BUILD_FIN_DIR --without-libpsl --disable-ldap --without-brotli --without-winidn --without-libidn2 --disable-shared --disable-crypto-auth --disable-ftp --disable-telnet --disable-gopher --disable-dict --disable-imap --disable-pop3 --disable-rtsp --disable-smtp --disable-tftp
	#CFLAGS=-fPIC make -j10 install

	#install it
	#cp $PWD/lib/libcurl.a $BUILD_FIN_DIR/
	#cp -r $PWD/include/curl $BUILD_FIN_DIR/

	#cd ../

	echo "Building Glew..."
	sleep 1.5
	wget -O glewz.zip "https://sourceforge.net/projects/glew/files/glew/2.2.0/glew-2.2.0.zip/download"
    	unzip glewz.zip -d glew
    	cd glew/glew-2.2.0

    	mkdir lib/
    	mkdir bin/
    	gcc -DGLEW_NO_GLU -O2 -Wall -W -Iinclude -DGLEW_BUILD -o src/glew.o -c src/glew.c
    	gcc -nostdlib -shared -Wl,-soname,libglew32.dll -Wl,--out-implib,lib/libglew32.dll.a -o lib/glew32.dll src/glew.o -L/mingw/lib -lglu32 -lopengl32 -lgdi32 -luser32 -lkernel32
    	ar cr lib/libglew32.a src/glew.o
    	gcc -DGLEW_NO_GLU -DGLEW_MX -O2 -Wall -W -Iinclude -DGLEW_BUILD -o src/glew.mx.o -c src/glew.c
    	gcc -nostdlib -shared -Wl,-soname,libglew32mx.dll -Wl,--out-implib,lib/libglew32mx.dll.a -o lib/glew32mx.dll src/glew.mx.o -L/mingw/lib -lglu32 -lopengl32 -lgdi32 -luser32 -lkernel32
    	ar cr lib/libglew32mx.a src/glew.mx.o

	install it
	cp $PWD/lib/libglew32.a $BUILD_FIN_DIR/
	cp -r $PWD/include $BUILD_FIN_DIR/
	
	cd ../../

	#echo "Building SDK..."
	#sleep 1.5
	#wget -O sdkz "http://developer.x-plane.com/wp-content/plugins/code-sample-generation/sample_templates/XPSDK303.zip"
	#unzip sdkz -d SDK
	#cd SDK
	
	#install it
	#cp -r $PWD/SDK $BUILD_FIN_DIR/
	
	#cd ../

	echo "Building dependency Pixman..."
	sleep 1.5
	git clone --recursive "https://github.com/freedesktop/pixman.git" pixman
	cd pixman
	./autogen.sh --prefix=$BUILD_FIN_DIR --enable-static --disable-shared --disable-libpng --disable-gtk --disable-static-testprogs --disable-openmp
    	make
    	make install
    	cd ../

	echo "Building dependency Freetype..."
	sleep 1.5
	git clone --recursive "https://github.com/aseprite/freetype2.git" freetype
	cd freetype
	./autogen.sh --enable-static --disable-shared --without-harfbuzz
	make
	make
	#move build libs/includes
	cd objs/.libs
	cp $PWD/libfreetype.a $BUILD_FIN_DIR
	cd ../../
	cp -r $PWD/include $BUILD_FIN_DIR
	cd ../

	echo "Building dependency Cairo..."
	sleep 1.5
	git clone --recursive "https://github.com/freedesktop/cairo.git" cairo
	cd cairo
	export pixman_CFLAGS=-I$BUILD_FIN_DIR/include/pixman-1
    	export pixman_LIBS=$BUILD_FIN_DIR/lib/libpixman-1.a
    	export FREETYPE_CFLAGS=-I$BUILD_FIN_DIR/include/
    	export FREETYPE_LIBS=$BUILD_FIN_DIR/libfreetype.a
    	./autogen.sh --prefix=$BUILD_FIN_DIR --enable-static --disable-egl --disable-glesv2 --disable-glesv3 --disable-glx --disable-gl --disable-valgrind --disable-xlib --enable-ft --disable-shared --disable-xlib-xrender --disable-xcb --disable-svg --disable-full-testing --disable-interpreter --disable-fc --disable-ps --disable-pdf --disable-glesv2 --enable-win32 --disable-win32-font --disable-drm --disable-png --disable-script --disable-quartz --disable-wgl --disable-gobject --disable-trace --disable-symbol-lookup
    	#sed -i src/cairo-misc.c -e "s/^#ifdef _WIN32 \/\* also defined on x86_64 \*\//#if 0/gi"
    	#sed -i build/configure.ac.warnings -e "^s/MAYBE_WARN=\"\$MAYBE_WARN -Wp,-D_FORTIFY_SOURCE=2\"//gi"
    	make -j10
    	make install
    	cd ../

	echo "Building dependency GLFW..."
	wget -O glfwz "https://github.com/glfw/glfw/releases/download/3.3.2/glfw-3.3.2.bin.WIN64.zip"
	unzip glfwz -d glfw

	cp -r glfw/glfw-3.3.2.bin.WIN64/include $BUILD_FIN_DIR
	cp glfw/glfw-3.3.2.bin.WIN64/lib-mingw-w64/libglfw3.a $BUILD_FIN_DIR
	

		
}

build_deps_win