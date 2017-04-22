#include "geneticalgorithm.h"

int mypow(int number, int expoent){
    int i, aux = number;
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
    //std::cout << "send"<< number1 << "more"<< number2 << '\n';
    number1 = number1 + number2;
    number3 = vet[4]*mypow(10,4) + vet[5]*mypow(10,3) + vet[2]*mypow(10,2) + vet[1]*mypow(10,1) + vet[7];
    //std::cout << "money"<< number3<< '\n';
    vet[10] = abs(number1 - number3);
}
/*
bool verify(int *vet, int number, int range){
    int i;
    for(i = 0; i < range; i++){
        if(vet[i] == number){
            return false;
        }
    }
    return true;
}*/

int verify1(int *vet, int number, int range){
    int i;
    for(i = 0; i < range; i++){
        if(vet[i] == number){
            return 0;
        }
    }
    return 1;
}

void percentage(int solution[100][12], float qtd[9]){
    int i, j;
    for(i = 0; i < 100; i++){
        for(j = 0; j < 8; j++){
            qtd[solution[i][j]] += 1;
        }
    }
}

int maxelement(int solutions[100][12], int *tournamentelements, int tour){

    int i, max = 0;

    for(i = 0; i < tour; i++){
        if(solutions[tournamentelements[max]][10] < solutions[tournamentelements[i]][10]){
            max = i;
        }
    }
    return tournamentelements[max];
}

int minelement(int solutions[100][12], int *tournamentelements, int tour){

    int i, min = 0;

    for(i = 0; i < tour; i++){
        if(solutions[tournamentelements[min]][10] > solutions[tournamentelements[i]][10]){
            min = i;
        }
    }
    return tournamentelements[min];
}

int calctcross_int(int population, int percentage){

    int resp;
    resp = population * percentage;
    resp = resp/100;

    return resp;

}

int search(int vet[10], int value){
    int i;
    for(i = 0; i < 10; i++){
        if(vet[i] == value){
            return i;
        }
    }
    return i;
}

void print(int *vet,int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d ",vet[i]);
    }
    printf("\n");


}

void crossover(int solutions[180][12], int parent1[10], int parent2[10], int number, int range){

    int aux[10], current, i;
    memset(aux, -1, sizeof aux);
    aux[number] = parent1[number];
    current = search(parent1,parent2[number]);
    while(aux[number] != parent1[current]){
        aux[current] = parent1[current];
        current = search(parent1, parent2[current]);
    }
    for(i = 0;i < 10; i++){

        if(aux[i] != -1){
            solutions[100 + range - 1][i] = parent2[i];
            solutions[100 + range][i] = parent1[i];
        }else{
            solutions[100 + range - 1][i] = parent1[i];
            solutions[100 + range][i] = parent2[i];
        }
    }

    calcnumbers(solutions[100 + range - 1]);
    calcnumbers(solutions[100 + range]);

}


void quickSort(int solutions[180][12],int *vet, int comeco, int fim){
    int pivot, aux;
	int i, j;

	pivot = vet[(comeco+fim)/2];
	i = comeco;
	j = fim;

	while(i <= j){
		while(solutions[vet[i]][10] < solutions[pivot][10])
			i++;

		while(solutions[vet[j]][10] > solutions[pivot][10])
			j--;

		if(i <= j){
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;j--;
        }
	}

	if(j > comeco)
		quickSort(solutions, vet, comeco, j);

	if(i < fim)
		quickSort(solutions, vet, j+1, fim);

}

void printmatrix(int solutions[180][12]){
    int i;
    printf("\n");
    for(i = 0; i < 180; i++){

        print(solutions[i],11);

    }
    printf("\n");

}
