#pragma once

#define DEFAULT_WEIGHT 0
#define NNEURON 1
using Random = std::default_random_engine;
using namespace std;

class Number{
    int representation[31];
    int weight[31][NNEURON];

public:
    Number();
    Number(int option);
    void setRepresentation(int representation[31]);
    int* getRepresentation();
    void setWeigt(int weight[31]);
    int* getWeight();
}