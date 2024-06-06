CXX:= g++
TESTFLAGS:= -lgtest -lgtest_main # Flags used to compile the tests
LDFLAGS:= ${shell fltk-config --ldstaticflags}

# Pattern match source files to object files
GUISRC:= ${wildcard ./src/*.cpp}
GUIOBJ:= ${GUISRC:%.cpp=build/%.o}
STRLIBSRC:= ${wildcard ./src/strlib/*.cpp}
STRLIBOBJ:= ${STRLIBSRC:%.cpp=build/%.o}

# Compiles the gui application
all: ${GUIOBJ} ${STRLIBOBJ}
	${CXX} ${GUIOBJ} ${STRLIBOBJ} -o ./build/string-tension ${LDFLAGS}

# Individually compile object files in the build directory
build/%.o: %.cpp
	mkdir -p ${dir $@}
	${CXX} -c $< -o $@

# Compiles the testing program
test: ${STRLIBOBJ}
	${CXX} ./test/*.cpp ${STRLIBOBJ} -o ./build/test ${TESTFLAGS}

clean:
	rm -rf ./build
