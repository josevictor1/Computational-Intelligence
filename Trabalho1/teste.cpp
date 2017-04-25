#include "geneticalgorithm.h"

using namespace std;

int main(){
    int parents[80];
    int sorted[180];
    int i, j, number,n,solutions[180][12],sons[180][12], parent1[10], parent2[10], tcross = 80;
    srand(time(NULL));
    for(i = 0;i < 100; i++){
        for(j = 0; j < 10;j ++){
            number = rand()%10;
            //Verify wether the generated number belongs to the vector
            while (verify(solutions[i],number,j) == false){
                number = rand()%10;
            }
            solutions[i][j] = number;
        }
        calcnumbers(solutions[i]); //Second Version
    }

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
    parent2[8] = 9;
    parent2[9] = 0;


    /*
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
    */

    /*for(i = 0;i < 100; i++){
        for(j = 0; j < 11;j ++){
            printf(" %d ", solutions[i][j]);
        }
        printf("\n %d ", solutions[i][10]);
        printf("\n");
    }*/


/*
    int tour = 3, tournamentelements[3];

    for(i = 0; i < 80; i++){
        printf("\n");
        number = rand()%100;
        for (j = 0; j < tour; j++) {
            while(verify(tournamentelements, number, j) == false){
                number = rand()%100;
            }

            tournamentelements[j] = number;

            printf("Telements %d\n",solutions[tournamentelements[j]][11]);

        }
        printf("\n");
        parents[i] = minelement(solutions, tournamentelements, tour);
        printf("Minimum %d \n",solutions[parents[i]][11]);
    }

    printf("\n");
*/

    for(i = 0; i < 10; i ++){
        number = abs(rand())%10;
        //printf("\nparent 1: ");
        //print(solutions[parents[i-1]],10);
        //printf("\n parent 2: ");
        //print(solutions[parents[i]],10);
        //print(solutions[parents[i-1]],12);
        //print(solutions[parents[i]],12);
        //printf("%d\n",number);
        //printf("%d\n",i);
        crossover(solutions, parent1, parent2, i%10, 1);


    }


}
