#pragma once
#include <utility>
#include <iostream>
#include <random>

#define DEFAULT_WEIGHT 0
#define NNEURONS 1
#define NNUMBERS 6
#define ENTRYS 31
//using Random = std::default_random_engine;
using namespace std;


class Number{
    int number;
    double representation[31];   
    

public:
   
    void setNumber(int number);
    int getNumber();
    void printNumber();    
    void choiceRepresentation();
    void setRepresentation(double representation[31]);
    double* getRepresentation();
    void invertNumbers(int position);
    void generateModifications(int nmodifications);
    void setWithLetter(int option);
};