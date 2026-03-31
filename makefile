p?=tests/vector/
f?=life_cycle
b?=n
clear_screen?=s
run?=s

all: init compile clear run

init:
	@if [ "$(b)" = "s" ]; then \
		rm -rf build; \
	fi

	@mkdir -p build

compile:
	cd build && cmake -DCOMPILE_TARGET_PATH="$(p)" -DCOMPILE_TARGET="$(f)" .. && make

clear:
	@if [ "$(clear_screen)" = "s" ]; then \
		clear; \
	fi

run:
	@if [ "$(run)" = "s" ]; then \
		cd build && ./Executable; \
	fi