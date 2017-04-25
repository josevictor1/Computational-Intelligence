#include "geneticalgorithm.h"

using namespace std;

int main(){
    int i, n,sons[180][12], parent1[10], parent2[10];
    parent1[0] = 7;
    parent1[1] = 5;
    parent1[2] = 1;
    parent1[3] = 4;
    parent1[4] = 3;
    parent1[5] = 6;
    parent1[6] = 8;
    parent1[7] = 2;
    parent1[8] = 0;
    parent1[9] = 9;

    parent2[0] = 3;
    parent2[1] = 4;
    parent2[2] = 8;
    parent2[3] = 7;
    parent2[4] = 5;
    parent2[5] = 2;
    parent2[6] = 6;
    parent2[7] = 1;
    parent2[8] = 0;
    parent2[9] = 9;


    //for(i = 0; i < 10; i++){
    //    printf("%d ", parent1[i]);
    //}
    //printf("\n");
    //for(i = 0; i < 10; i++){
    //    printf("%d ", parent2[i]);
    //}

    crossover(sons, parent1, parent2, 2,1);
    printf("\n");

    print(sons[100], 10);
    print(sons[101], 10);
}
