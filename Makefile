CXX:= g++
BUILD:= ./build
STRLIB:= ./src/strlib
strlib: build
	${CXX} -c ${STRLIB}/stringweight.cpp -o ${BUILD}/stringweight.o
	${CXX} -c ${STRLIB}/stringlists.cpp -o ${BUILD}/stringlists.o
	${CXX} -c ${STRLIB}/strlib.cpp -o ${BUILD}/strlib.o

build:
	mkdir ${BUILD}

clean:
	rm -rf ${BUILD}