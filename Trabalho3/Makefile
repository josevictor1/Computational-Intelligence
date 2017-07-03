ALL = redesneurais

CXX = clang++
CXXFLAGS += -g -std=c++11 -Wall

.PHONY: all clean rebuild

all: $(ALL)
	@sync
clean:
	@$(RM) $(ALL)

rebuild: clean all

redesneurais: Number.cpp Main.cpp Neuron.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@
