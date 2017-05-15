#include "geneticalgorithm.h"

int main(int argc, char const *argv[]) {

    int solutions[TPOP][12];
    int parents[TCROS];
    int Nger;
    int experiment;
    int count;
    bool find;
    float timeprogram, average_convergence = 0, average_time = 0;
    time_t t,t_begin,t_end;
    int average_iterator;

    for(average_iterator = 0; average_iterator < 10; average_iterator++){
        count = 0;
        t_begin = time(NULL);
        int amostra = 0;
        for(experiment = 0; experiment < EXPER; experiment++){
            // Generate the population
            int number, i, j;
            find = true;

            srand(experiment*1000*time(&t)+average_iterator);

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
            //cleanarray(parents,TCROS);

            while (find && Nger < NGEN){
                if(OPTR == 0){
    		//Tournament
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
    		//Roullete
                    int total, sum, random;
                    j = 0;// maybe is necessary to acumullate the value of the sum in another matrix position
                    //quickSort(solutions, 0, 99, 11);
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
                else if(OPTR == 2){
                    int total, sum, random, k;
                    int tournamentelements[TOUR];
                    for(k = 0; k < TCROS; k++){
                        j = 0;// maybe is necessary to acumullate the value of the sum in another matrix position
                        total = calctotal(solutions);
                        for(i = 0; i < TOUR; i++){
                            sum = solutions[0][11];
                            random = rand()%total;
                            //j = 0;
                            while(sum < random){
                                j++;
                                sum = sum + solutions[j%POP][11];
                            }
                            tournamentelements[i] = j%POP;
                        }
                        parents[k] = minelement(solutions, tournamentelements, TOUR);
                    }
                }

                for(i = 1; i < TCROS; i = i + 2){
                    number = rand()%10;
                    //printf("%d\n",number);
                    crossover(solutions, solutions[parents[i-1]], solutions[parents[i]], number, i);
                }
                int n1, n2, p, mut;

                //Selecting the mutation's subjects aleatorialy

                for(i = POP; i < TPOP; i++){
                    for(mut = 0; mut < QTDMUT; mut++){
                        p = rand()%POP;
                        n1 = rand()%10;
                        n2 = rand()%10;
                        while (n1 == n2) {
                            n2 = rand()%10;
                        }
                        if(p <= PMUT){
                            number = solutions[i][n1];
                            solutions[i][n1] = solutions[i][n2];
                            solutions[i][n2] = number;
                            calcnumbers(solutions[i]);
                        }
                    }
                }

                if(ELITE == 0){
                    quickSort(solutions, 0, TPOP - 1, 10);
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

                    /*if(Nger == 100){
                        amostra++;
                        printf("%d\n", amostra);
                    }*/
                }
            }
        }
    	t_end = time(NULL);
    	timeprogram = difftime(t_end, t_begin);
	    printconfiguration(count,timeprogram);
        average_time += timeprogram;
        average_convergence += (float(count)*100)/EXPER;
        //printf("%d\n",experiment);
        //printf("average_convergence: %d\n", average_convergence);
    }
    printf("\nMédia de tempo: %f \\\\ \n", average_time/average_iterator);
    printf("Média de convergência: %f\n", average_convergence/average_iterator);

    return 0;
}
