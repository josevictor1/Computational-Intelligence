ALL = antcolony

CXX = clang++
CXXFLAGS += -g -std=c++11 -Wall

.PHONY: all clean rebuild

all: $(ALL)
	@sync

clean:
	@$(RM) $(ALL)

rebuild: clean all

antcolony: Ant.cpp Graph.cpp Main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
