#include "geneticalgorithm.h"

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int solutions[100][12];
    int  i, j, number, average = 0, max = 0, min = 0;
    float qtd[10];
    //std::cin >> number;
    //std::cout << mypow(number,2) << '\n';

    for(i = 0;i < 100; i++){
        for(j = 0; j < 8;j ++){
            number = rand()%10;
            //Verify wether the generated number belongs to the vector
            while (verify(solutions[i],number,j) == false){
                number = rand()%10;
            }
            solutions[i][j] = number;
        }
        calcnumbers(solutions[i]); //Second Version
    }

    for(i = 0; i < 100; i++){
        for(j = 0; j < 8; j++){
            printf(" %d ",solutions[i][j]);
        }
        printf(" %d ",solutions[i][11]);
        printf("\n");
    }
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
    for(i = 0; i < 100; i++){
        // calc send + more to the i-esimo and to the max index

        average += solutions[i][11];
        //resultcalculated = send + more
        if( solutions[i][11] > solutions[max][11]){
            max = i;
        }

        if(solutions[i][11] < solutions[min][11]){
            min = i;
        }
    }


    average = abs(average/100);

    /*Estatistics*/
    /*MAX*/
    //int result, resultcalculated; First Version

    printf("Average: %d\n",average);
    printf("Max vector: ");
    for(i = 0; i < 8; i++){
        printf(" %d ",solutions[max][i]);
    }
    printf("fitness %d\n", solutions[max][11]);
    /*First Version
    calcnumbers(solutions[max],&resultcalculated,&resul);
    printf("fitness: %d\n",abs(resultcalculated - result));
    */
    /*MIN*/
    printf("Min vector: ");
    for(i = 0; i < 8; i++){

        printf(" %d ",solutions[min][i]);
    }
    printf("fitness %d\n", solutions[min][11]);
    /*First Version
    calcnumbers(solutions[min],&resultcalculated,&result);
    printf("fitness: %d\n",abs(resultcalculated - result));
    */
    /*Percentage's recunrence of each element*/
    for(i = 0; i < 10; i++){
        qtd[i] = 0;
    }

    percentage(solutions,qtd);

    printf("Probability:\n");

    for(i = 0; i < 10; i++){
        printf("*%d - %0.2f per cent\n",i,(qtd[i]/8));
    }

    /*Tournament*/

    int tour = 3, tournamentelements[3];

    number = rand()%100;
    for (i = 0; i < tour; i++) {
        while(verify(tournamentelements,number,i) == false){
            number = rand()%3;
        }
        tournamentelements[i] = number;
    }
    max = maxelement(solutions,tournamentelements,tour);

    printf("\nTournament Method\n");
    printf("The maximum element by Tournament Method %d\n",solutions[max][11]);



    return 0;
}
