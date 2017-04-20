#include "geneticalgorithm.h"

using namespace std;

int main(){
    int i, n,sons[180][12], parent1[10], parent2[10];

    for(i = 0; i < 10; i++){
        scanf("%d", &parent1[i] );
    }

    for(i = 0; i < 10; i++){
        scanf("%d", &parent2[i] );
    }

    for(i = 0; i < 10; i++){
        printf("%d ", parent1[i]);
    }
    printf("\n");
    for(i = 0; i < 10; i++){
        printf("%d ", parent2[i]);
    }

    crossover(sons, parent1, parent2, 5,1);
    printf("\n");

    print(sons[80], 10);
    print(sons[79], 10);
}
