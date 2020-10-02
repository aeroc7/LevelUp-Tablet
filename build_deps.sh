function build_deps_lin()
{
	echo "Building Dependencies..."
	sleep 1.5

	mkdir $PWD/deps
	mkdir $PWD/temp_dls

	BUILD_FIN_DIR=$PWD/deps

	cd temp_dls

	echo "Building zlib..."
	sleep 1.5
	git clone --recursive "https://github.com/madler/zlib.git"
	cd zlib
	./configure --prefix=$PWD/build
	make
	make install

	#install it to our directory
	cp $PWD/build/lib/libz.a $BUILD_FIN_DIR/

	cd ../

	echo "Building mbedtls..."
	sleep 1.5
	git clone --recursive "https://github.com/ARMmbed/mbedtls.git"
	cd mbedtls
	cmake -D CMAKE_BUILD_TYPE=Release .
	make

	#install it
	cp $PWD/library/libmbedtls.a $BUILD_FIN_DIR/

	cd ../

	echo "Building OpenSSL..."
	sleep 1.5
	git clone --recursive "https://github.com/openssl/openssl.git"
	cd openssl
	./config
	make
	sudo make install

	#install it
	cp $PWD/libcrypto.a $BUILD_FIN_DIR/
	cp $PWD/libssl.a $BUILD_FIN_DIR/

	cd ../

	echo "Building cUrl..."
	sleep 1.5
	git clone --recursive "https://github.com/curl/curl.git"
	cd curl
	./buildconf
	./configure --prefix=$PWD --with-ssl=$BUILD_FIN_DIR --without-nghttp2 --with-mbedtls=$BUILD_FIN_DIR --with-zlib=$BUILD_FIN_DIR --without-libpsl --disable-ldap --without-brotli --without-winidn --without-libidn2 --disable-shared --disable-crypto-auth --disable-ftp --disable-telnet --disable-gopher --disable-dict --disable-imap --disable-pop3 --disable-rtsp --disable-smtp --disable-tftp
	CFLAGS=-fPIC make -j10 install

	#install it
	cp $PWD/lib/libcurl.a $BUILD_FIN_DIR/
	cp -r $PWD/include/curl $BUILD_FIN_DIR/

	cd ../

	echo "Building Glew..."
	sleep 1.5
	wget -O glewz "https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0.zip/download"
    	unzip glewz -d glew
    	cd glew/glew-2.1.0
    	make -j10

	#install it
	cp $PWD/lib/libGLEW.a $BUILD_FIN_DIR/
	cp -r $PWD/include $BUILD_FIN_DIR/
	
	echo "Building SDK..."
	sleep 1.5
	wget -O sdkz "http://developer.x-plane.com/wp-content/plugins/code-sample-generation/sample_templates/XPSDK303.zip"
	unzip sdkz -d SDK
	cd SDK
	
	#install it
	cp -r $PWD/SDK $BUILD_FIN_DIR/

	cd ../../../

	rm -rf temp_dls

	echo "Finished!"
}

build_deps_lin
