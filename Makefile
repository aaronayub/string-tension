CXX:= g++
BUILD:= ./build
STRLIB:= ./src/strlib
TESTFLAGS:= -lgtest -lgtest_main # Flags used to compile the tests

strlib.a: build
	${CXX} -c ${STRLIB}/stringweight.cpp -o ${BUILD}/strlib/stringweight.o
	${CXX} -c ${STRLIB}/stringlists.cpp -o ${BUILD}/strlib/stringlists.o
	${CXX} -c ${STRLIB}/strlib.cpp -o ${BUILD}/strlib/strlib.o
	ar rcs ${BUILD}/strlib.a ${BUILD}/strlib/*.o

build:
	mkdir ${BUILD}
	mkdir ${BUILD}/strlib

clean:
	rm -rf ${BUILD}

test: ${BUILD}/strlib.a
	g++ test/*.cpp ${BUILD}/strlib.a ${TESTFLAGS} -o ${BUILD}/test