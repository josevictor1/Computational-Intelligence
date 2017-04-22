#include "geneticalgorithm.h"

int main(int argc, char const *argv[]) {

    int solutions[TPOP][12];
    int parents[TCROS];
    int sorted[TPOP];
    int Nger;
    int experiment;
    int count = 0;
    bool find;
    time_t t;
    for(experiment = 0; experiment < EXPER; experiment++){
        // Generate the population
        int number, i, j;
        find = true;

        srand(time(NULL)*experiment);

        for(i = 0;i < TPOP - TCROS; i++){
            for(j = 0; j < 10;j ++){
                number = rand()%10;
                //Verify wether the generated number belongs to the vector
                while(!verify(solutions[i],number,j)){
                    number = rand()%10;
                }
                solutions[i][j] = number;
            }
            calcnumbers(solutions[i]); //Second Version
        }
        for(i = 0; i < 180; i++){
            sorted[i] = i;
        }
        Nger = 0;
        cleanarray(parents,TCROS);

        while (find && Nger < NGEN){

            int tournamentelements[TOUR];

            for(i = 0; i < TCROS; i++){
                for (j = 0; j < TOUR; j++) {
                    number = rand()%100;
                    while(!verify(tournamentelements, number, j)){
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
                //printf("%d\n",number);
                crossover(solutions, solutions[parents[i-1]], solutions[parents[i]], number, i);
            }

            //printf("\n");



            int n1, n2, p;

            //Selecting the mutation's subjects altorialy

            for(i = 100; i < 180; i++){
                    p = rand()%100;
                    n1 = rand()%10;
                    n2 = rand()%10;
                    while (n1 == n2) {
                        n2 = rand()%10;
                    }
                    if(p <= 10){
                        number = solutions[i][n1];
                        solutions[i][n1] = solutions[i][n2];
                        solutions[i][n2] = number;
                        calcnumbers(solutions[i]);
                    }
            }

            for(i = 100; i < 180; i++){
                    p = rand()%100;
                    n1 = rand()%10;
                    n2 = rand()%10;
                    while (n1 == n2) {
                        n2 = rand()%10;
                    }
                    if(p <= 10){
                        number = solutions[i][n1];
                        solutions[i][n1] = solutions[i][n2];
                        solutions[i][n2] = number;
                        calcnumbers(solutions[i]);
                    }
            }

            quickSort(solutions, 0, 179);

            if(solutions[sorted[0]][10] == 0){
                count++;
                find = false;
            }
            else{
                Nger++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
