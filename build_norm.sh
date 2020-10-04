echo "Building Development Build"

if [ ! -d 'build/' ] then
	mkdir build
fi

if [[ "$OSTYPE" == 'msys' ]]; then
	cd build
	cmake -DCMAKE_BUILD_TYPE=Debug -DWIN32=On -DSTANDALONE_BUILD=On ..
	make
	
fi
