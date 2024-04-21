.PHONY: clean cmake build run

run:
	./build/main

build:
	cd build && make

cmake:
	mkdir build && cmake -DCMAKE_PREFIX_PATH=~/dev/cpp/cmake/08-sdl/libs -S . -B build 

clean:
	rm -rf build