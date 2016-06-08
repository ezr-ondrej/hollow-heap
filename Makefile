OBJECTS_DIR = objects

GTEST_PATH="/home/ondra/Documents/Projekty/googletest/googletest"

# Flags passed to the preprocessor.
# CPPFLAGS += -I$(GTEST_DIR)/include
# CPPFLAGS += -I$(SRC_DIR)

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pedantic -Wno-long-long -ggdb

OPT=-O2



build: libhollowheap.a

test: test.cpp libhollowheap.a
	${CXX} ${CPPFLAGS} $(CXXFLAGS) ${OPT} -I${GTEST_PATH}/include test.cpp -o tests -pthread -L${GTEST_PATH} -lgtest
	./tests

libhollowheap.a: hollow_heap.o
	ar rcs libhollowheap.a ${OBJECTS_DIR}/hollow_heap.o
	# ar -cvq libhollowheap.a ${OBJECTS_DIR}/hollow_heap.o

hollow_heap.o: hollow_heap.hpp hollow_heap.cpp ${OBJECTS_DIR}
	${CXX} ${CPPFLAGS} $(CXXFLAGS) ${OPT} -c hollow_heap.hpp -o ${OBJECTS_DIR}/hollow_heap.o


${OBJECTS_DIR}:
	@mkdir -p $@/

clean:
	rm libhollowheap.a
	rm -r ${OBJECTS_DIR}
