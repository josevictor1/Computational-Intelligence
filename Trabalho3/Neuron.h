#pragma once
#include "Number.h"

class Neuron{
    int recognize;
    //int u;
    //int y;
    double weight[31];
    
public:
    void setRecognize(int recognize);
    int getRecognize();
    double sigma(Number number);
    int limiar(double u);
    void setWeight(int op);
    void getWeight();
    void verify(Number number);
    int calculate(Number number[6], int range);
};