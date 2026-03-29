all:
	rm -rf build
	mkdir build
	cd build && cmake .. && make && clear && ./Executable
