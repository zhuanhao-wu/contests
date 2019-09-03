CXXFLAGS=-std=c++14

SRCS=$(shell find . -name "*.cpp")
TARGETS=$(subst .cpp,,$(SRCS))

$(TARGETS): %: %.cpp
	g++ $(CXXFLAGS) $*.cpp -o $*

clean:
	@rm -rf $(TARGETS)
