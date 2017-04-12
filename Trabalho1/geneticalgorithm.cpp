#include "geneticalgorithm.h"

int mypow(int number, int expoent){
    int i,aux = number;
    for(i = 0; i < expoent - 1; i++){
        number = number * aux;
        //std::cout << "number"<< number << '\n';
    }

    return number;
}
/*First Version
void calcnumbers(int *vet, int *resultcalculated, int *expectedresult){

    int number1 = 0, number2 = 0;
    //  | 0-s | 1-e | 2-n | 3-d | 4-m | 5-o|  6-r | 7-y |
    number1 = vet[0]*mypow(10,3) +  vet[1]*mypow(10,2) + vet[2]*mypow(10,1) + vet[3];
    number2 = vet[4]*mypow(10,3) +  vet[5]*mypow(10,2) + vet[6]*mypow(10,1) + vet[1];
    *resultcalculated = number1 + number2;
    *expectedresult = vet[4]*mypow(10,4) + vet[5]*mypow(10,3) + vet[2]*mypow(10,2) + vet[1]*mypow(10,1) + vet[7];
}
*/
/*Second Version, fitness function*/
void calcnumbers(int *vet){

    int number1 = 0, number2 = 0, number3 = 0;
    //  | 0-s | 1-e | 2-n | 3-d | 4-m | 5-o|  6-r | 7-y |
    number1 = vet[0]*mypow(10,3) +  vet[1]*mypow(10,2) + vet[2]*mypow(10,1) + vet[3];
    number2 = vet[4]*mypow(10,3) +  vet[5]*mypow(10,2) + vet[6]*mypow(10,1) + vet[1];
    number1 = number1 + number2;
    number3 = vet[4]*mypow(10,4) + vet[5]*mypow(10,3) + vet[2]*mypow(10,2) + vet[1]*mypow(10,1) + vet[7];
    vet[11] = abs(number2 - number3);
}

bool verify(int *vet, int number, int range){
    int i;
    for(i = 0; i < range; i++){
        if(vet[i] == number){
            return false;
        }
    }
    return true;
}

void percentage(int solution[100][12], float qtd[9]){
    int i, j;
    for(i = 0; i < 100; i++){
        for(j = 0; j < 8; j++){
            qtd[solution[i][j]] += 1;
        }
    }
}

int maxelement(int solutions[100][12], int *tournamentelements,int tour){

    int i, max = 0;

    for(i = 0; i < tour; i++){
        if(solutions[tournamentelements[max]][11] < solutions[tournamentelements[1]][11]){
            max = i;
        }
    }
    return tournamentelements[max];
}
