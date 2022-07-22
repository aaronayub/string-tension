CXX:= g++
BUILD:= ./build
STRLIB:= ./src/strlib
strlib: build
	g++ -c ${STRLIB}/stringweight.cpp -o ${BUILD}/stringweight.o
	g++ -c ${STRLIB}/strlib.cpp -o ${BUILD}/strlib.o

build:
	mkdir ${BUILD}

clean:
	rm -rf ${BUILD}