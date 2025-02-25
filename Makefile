NAME=ProjectAlchemy

all:
	cmake -DCMAKE_BUILD_TYPE=Debug-DCMAKE_BUILD_TYPE=Debug -S . -B build
	cmake --build build

run: all
	./build/$(NAME)/$(NAME)

clean:
	rm -rf build
	rm -f vgcore.*

.PHONY: all clean run
