#include "geneticalgorithm.h"

int main(int argc, char const *argv[]) {

    int solutions[TPOP][12];
    int parents[TCROS];
    //int sorted[TPOP][12];
    int Nger;
    int experiment;
    int count = 0;
    bool find;
    time_t t;
    for(experiment = 0; experiment < EXPER; experiment++){
        // Generate the population
        int number, i, j;
        find = true;

        srand(experiment*1000*time(&t));

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

        Nger = 0;
        cleanarray(parents,TCROS);

        while (find && Nger < NGEN){

            //case 1:
            if(OPTR == 0){
                int tournamentelements[TOUR];

                for(i = 0; i < TCROS; i++){
                    for (j = 0; j < TOUR; j++) {
                        number = rand()%POP;
                        while(!verify(tournamentelements, number, j)){
                            number = rand()%POP;
                        }
                        tournamentelements[j] = number;

                    }
                    parents[i] = minelement(solutions, tournamentelements, TOUR);
                }
            }
            else if(OPTR == 1){
                int total, sum, random;
                j = 0;
                quickSort(solutions, 0, 99, 11);
                total = calctotal(solutions);
                for(i = 0; i < TCROS; i++){
                   sum = solutions[0][11];
                   random = rand()%total;
                   //j = 0;
                   while(sum < random){
                       j++;
                       sum = sum + solutions[j%POP][11];
                   }
                   parents[i] = j%POP;
                }
                //print(parents,80);
            }

            for(i = 1; i < TCROS; i = i + 2){
                number = rand()%10;
                //printf("%d\n",number);
                crossover(solutions, solutions[parents[i-1]], solutions[parents[i]], number, i);
            }
            int n1, n2, p;

            //Selecting the mutation's subjects altorialy
            for(i = POP; i < 180; i++){
                p = rand()%POP;
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

            if(ELITE == 0){
                quickSort(solutions, 0, 179, 10);
            }
            else{
                elite(solutions);
            }

            if(solutions[0][10] == 0){
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
