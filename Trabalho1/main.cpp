#include "geneticalgorithm.h"

int main(int argc, char const *argv[]) {

    int solutions[180][12];
    int parents[80];
    int sorted[180];
    int Nger;
    int experiment,tcross = 80, pmut = 10;
    int solucion = 0;
    int count = 0;
    time_t t;
    bool find;
    for(experiment = 0; experiment < 100; experiment++){
        find = true;
        int number,i, j;
        srand(experiment*100);
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
        for(i = 0; i < 180; i++){
            sorted[i] = i;
        }
        while (find) {

            //float qtd[10];


            //srand(Nger*time(NULL));
            //std::cin >> number;
            //std::cout << mypow(number,2) << '\n';
            //srand(time(&t))

            //tcross = calctcross_int(100, tcross);



            //for(i = 0; i < 100; i++){
                //for(j = 0; j < 8; j++){
                    //printf(" %d ",solutions[i][j]);
                //}
                //printf(" %d ",solutions[i][11]);
                //printf("\n");
            //}
        /* First Version
            int aux1 = 0, aux2 = 0;
            for(i = 0; i < 100; i++){
                // calc send + more to the i-esimo and to the max index
                calcnumbers(solutions[i],&resultcalculated,&result);
                calcnumbers(solutions[max],&aux1,&aux2);
                average += abs(resultcalculated - result);
                //resultcalculated = send + more
                if(abs(resultcalculated - result) > abs(aux1 - aux2)){
                    max = i;
                }
                calcnumbers(solutions[min],&aux1,&aux2);
                if(abs(resultcalculated - result) < abs(aux1 - aux2)){
                    min = i;
                }
            }
        */
            //for(i = 0; i < 100; i++){
                // calc send + more to the i-esimo and to the max index

            //    average += solutions[i][11];
                //resultcalculated = send + more
            //    if( solutions[i][11] > solutions[max][11]){
            //        max = i;
            //    }

            //    if(solutions[i][11] < solutions[min][11]){
            //        min = i;
            //    }
            //}


            //average = abs(average/100);

            /*Estatistics*/
            /*MAX*/
            //int result, resultcalculated; First Version

            //printf("Average: %d\n",average);
            //printf("Max vector: ");
            //for(i = 0; i < 8; i++){
                //printf(" %d ",solutions[max][i]);
            //}
            //printf("fitness %d\n", solutions[max][11]);
            /*First Version
            calcnumbers(solutions[max],&resultcalculated,&resul);
            printf("fitness: %d\n",abs(resultcalculated - result));
            */
            /*MIN*/
            //printf("Min vector: ");
            //for(i = 0; i < 8; i++){

                //printf(" %d ",solutions[min][i]);
            //}
            //printf("fitness %d\n", solutions[min][11]);
            /*First Version
            calcnumbers(solutions[min],&resultcalculated,&result);
            printf("fitness: %d\n",abs(resultcalculated - result));
            */
            /*Percentage's recunrence of each element*/
            //for(i = 0; i < 10; i++){
            //    qtd[i] = 0;
            //}

            //percentage(solutions,qtd);

            //printf("Probability:\n");

            //for(i = 0; i < 10; i++){
                //printf("*%d - %0.2f per cent\n",i,(qtd[i]/8));
            //}

            /*Tournament*/

            int tour = 3, tournamentelements[3];

            /* After
            number = rand()%100;
            for (i = 0; i < tour; i++) {
                while(verify(tournamentelements,number,i) == false){
                    number = rand()%3;
                }
                tournamentelements[i] = number;
            }
            min = minelement(solutions,tournamentelements,tour);


            printf("\nTournament Method\n");
            printf("The maximum element by Tournament Method %d\n",solutions[min][11]);

            */

            for(i = 0; i < 80; i++){
                number = rand()%100;
                for (j = 0; j < tour; j++) {
                    while(verify(tournamentelements, number, j) == false){
                        number = rand()%100;
                    }
                    tournamentelements[j] = number;
                }
                parents[i] = minelement(solutions, tournamentelements, tour);
            }
            /*
            printf("\n");
            for ( i = 0; i < 10; i++) {
                std::cout << solutions[parents[0]][i] << " ";

            }

            printf("\n");
            printf("parent 2");
            for ( i = 0; i < 10; i++) {
                std::cout << solutions[parents[1]][i] << " ";

            }
            printf("\n");
            */

            for(i = 1; i < tcross; i = i + 2){
                number = rand()%10;
                //printf("\nparent 1: ");
                //print(solutions[parents[i-1]],10);
                //printf("\n parent 2: ");
                //print(solutions[parents[i]],10);
                print(solutions[parents[i-1]],12);
                print(solutions[parents[i]],12);
                printf("%d\n",number);
                crossover(solutions, solutions[parents[i-1]], solutions[parents[i]],number, i);
                print(solutions[parents[i-1]],12);
                print(solutions[parents[i]],12);
            }

            printf("passou1\n");


            int n1, n2, p;

            //Selecting the mutation's subjects altorialy

            for(i = 100; i < 180;i++){
                    //p = 100 + (rand()%80);

                //n2 = (rand()*Nger)%10;
                    p = rand()%80;
                    //p = p + 100;
                    n1 = (rand())%10;
                    n2 = (rand())%10;
                    while (n1 == n2) {
                        n2 = rand()%10;
                    }

                    printf("n1: %d\n",n1);
                    printf("n2: %d\n",n2);
                    if(p <= 10){
                        printf(" passou\n");
                        number = solutions[i][n1];
                        solutions[i][n1] = solutions[i][n2];
                        solutions[i][n2] = number;
                        calcnumbers(solutions[i]);
                    }
            }



            //}



            quickSort(solutions, sorted, 0, 179);

            //printf("\n");
            //for(i = 0;i < 180; i++){
            //    printf(" %d ",solutions[sorted[i]][10]);
            //}
            //printf("\n");
        //}

        //printf("%d\n" , solutions[sorted[0]][11]);
        //if(solutions[sorted[0]][11] == 0)
        //    solucion++;

        //printf("\n");
        //for(i = 0; i < 10; i++){
        //    printf(" %d ",solutions[sorted[0]][i]);
        //}
            if(solutions[sorted[0]][10] == 0){
                printf("achou \n");
                for (i = 0; i < 8; i++) {
                    printf("%d ",solutions[sorted[0]][i]);
                }
            //}
                count++;
                find = false;

            }
            else if(Nger == 200){
                printf("\n");
                for (i = 0; i < 8; i++) {
                    printf("%d ",solutions[sorted[0]][i]);
                }
                find = false;
            }else{
                Nger++;
            }


    }
    //printf("%d\n",count);
}
    printf(" qtd: %d\n",count);
    //printf("%d\n",solucion);
    return 0;
}
