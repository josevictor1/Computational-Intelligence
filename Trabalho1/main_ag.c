#include "geneticalgorithm.h"
#define TPOP 180
#define TCROS 80
#define PMUT 10
#define NGEN 200
#define NELEMENT 10
#define EXPER 100
#define TOUR 3

int main(int argc, char const *argv[]) {

    int solutions[TPOP][12];
    int parents[TCROS];
    int sorted[TPOP];
    int Nger;
    int experiment;
    int count = 0;
    int find;
    time_t t;
    for(experiment = 0; experiment < EXPER; experiment++){
        // Generate the population
        int number, i, j;
        find = 1;
        srand(experiment);
        for(i = 0;i < TPOP - TCROS; i++){
            for(j = 0; j < 10;j ++){
                number = rand()%10;
                //Verify wether the generated number belongs to the vector
                while(!verify1(solutions[i],number,j)){
                    number = rand()%10;
                }
                solutions[i][j] = number;
            }
            calcnumbers(solutions[i]); //Second Version
        }
        for(i = 0; i < 180; i++){
            sorted[i] = 0;
        }
        Nger = 0;
        while (find && Nger < NGEN){

            int tournamentelements[3];

            for(i = 0; i < TCROS; i++){
                for (j = 0; j < TOUR; j++) {
                    number = rand()%100;
                    while(!verify1(tournamentelements, number, j)){
                        number = rand()%100;
                    }
                    tournamentelements[j] = number;

                }
                parents[i] = minelement(solutions, tournamentelements, TOUR);
            }

            //printf("antes do crossover\n");
            //printmatrix(solutions);
/*
            for(i = 0; i < 80; i++){
                for(j = 0; j < 10; j++){
                    printf(" %d ",solutions[parents[i]][j]);
                }
                printf("\n");
            }
*/
            for(i = 1; i < TCROS; i = i + 2){
                number = rand()%10;
                printf("%d\n",number);
                crossover(solutions, solutions[parents[i-1]], solutions[parents[i]], number, i);
            }

            //printf("\n");



            int n1, n2, p;

            //Selecting the mutation's subjects altorialy

            for(i = 100; i < 180; i++){
                    p = rand()%80;
                    n1 = rand()%10;
                    n2 = rand()%10;
                    while (n1 == n2) {
                        n2 = rand()%10;
                    }
                    if(p <= 8){
                        number = solutions[i][n1];
                        solutions[i][n1] = solutions[i][n2];
                        solutions[i][n2] = number;
                        calcnumbers(solutions[i]);
                    }
            }

            quickSort(solutions, sorted, 0, 179);


            if(solutions[sorted[0]][10] == 0){
                //print(solutions[sorted[0]],11);
                count++;
                find = 0;
            }
            else{
                Nger++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
