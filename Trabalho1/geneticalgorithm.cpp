#include "geneticalgorithm.h"


int mypow(int number, int expoent){
    int i, aux = number;
    for(i = 0; i < expoent - 1; i++){
        number = number * aux;
        //std::cout << "number"<< number << '\n';
    }

    return number;
}

void cleanarray(int *vet, int n){
    int i;

    for (i = 0; i < n; i++){
        vet[i] = 0;
    }
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
    if(CRIPTOPT == 0){
        number1 = vet[0] * mypow(10,3) + vet[1] * mypow(10,2) + vet[2] * mypow(10,1) + vet[3];
        number2 = vet[4] * mypow(10,3) + vet[5] * mypow(10,2) + vet[6] * mypow(10,1) + vet[1];
        number3 = vet[4] * mypow(10,4) + vet[5] * mypow(10,3) + vet[2] * mypow(10,2) + vet[1] * mypow(10,1) + vet[7];
    }
    // | 0-e | 1-a | 2-t | 3-h | 4-p | 5-l |
    else if(CRIPTOPT == 1){
        number1 = vet[0] * mypow(10,2) + vet[1] * mypow(10,1) + vet[2];
        number2 = vet[2] * mypow(10,3) + vet[3] * mypow(10,2) + vet[1] * mypow(10,1) + vet[2];
        number3 = vet[1] * mypow(10,4) + vet[4] * mypow(10,3) + vet[4] * mypow(10,2) + vet[5] * mypow(10,1) + vet[0];
    }
    // | 0-c | 1-r | 2-o | 3-s | 4-a | 5-d | 6-n | 7-g | 8-e |
    else if(CRIPTOPT == 2){
        number1 = vet[0] * mypow(10,4) + vet[1] * mypow(10,3) + vet[2] * mypow(10,2) + vet[3] * mypow(10,1) + vet[4];
        number2 = vet[1] * mypow(10,4) + vet[2] * mypow(10,3) + vet[4] * mypow(10,2) + vet[5] * mypow(10,1) + vet[3];
        number3 = vet[5] * mypow(10,5) + vet[4] * mypow(10,4) + vet[6] * mypow(10,3) + vet[7] * mypow(10,2) + vet[8] * mypow(10,1) + vet[1];
    }
    // | 0-c | 1-o | 2-a | 3-l | 4-s | 5-i |
    else if(CRIPTOPT == 3){
        number1 = vet[0] * mypow(10,3) + vet[1] * mypow(10,2) + vet[0] * mypow(10,1) + vet[2];
        number2 = vet[0] * mypow(10,3) + vet[1] * mypow(10,2) + vet[3] * mypow(10,1) + vet[2];
        number3 = vet[1] * mypow(10,4) + vet[2] * mypow(10,3) + vet[4] * mypow(10,2) + vet[5] * mypow(10,1) + vet[4];
    }
    // | 0-d | 1-o | 2-n | 3-a | 4-l | 5-g | 6-e | 7-r | 8-b | 9-t |
    else if(CRIPTOPT == 4){
        number1 = vet[0] * mypow(10,5) + vet[1] * mypow(10,4) + vet[2] * mypow(10,3) + vet[3] * mypow(10,2) + vet[4] * mypow(10,1) + vet[0];
        number2 = vet[5] * mypow(10,5) + vet[6] * mypow(10,4) + vet[7] * mypow(10,3) + vet[3] * mypow(10,2) + vet[4] * mypow(10,1) + vet[0];
        number3 = vet[7] * mypow(10,5) + vet[1] * mypow(10,4) + vet[8] * mypow(10,3) + vet[6] * mypow(10,2) + vet[7] * mypow(10,1) + vet[9];
    }
    number1 = number1 + number2;

    if(TYPEFIT == 0){
        vet[10] = abs(number1 - number3);
    }
    else{
        int digit1, digit2;
        vet[10] = MAXFIT;
        while(number1 >= 1 && number3 >= 1){
            //printf("number 1: %d\n", number1);
            //printf("number 3: %d\n", number3);
            digit1 = number1%10;
            digit2 = number3%10;
            if(digit1 == digit2){
                vet[10]--;
                //printf("%d\n",vet[10]);
            }
            number1 = number1/10;
            number3 = number3/10;
        }
    }
    vet[11] = MAXFIT - vet[10];
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

void percentage(int solution[TPOP][12], float qtd[9]){
    int i, j;
    for(i = 0; i < 100; i++){
        for(j = 0; j < 8; j++){
            qtd[solution[i][j]] += 1;
        }
    }
}

int maxelement(int solutions[TPOP][12], int *tournamentelements, int tour){

    int i, max = 0;

    for(i = 0; i < tour; i++){
        if(solutions[tournamentelements[max]][10] < solutions[tournamentelements[i]][10]){
            max = i;
        }
    }
    return tournamentelements[max];
}

int minelement(int solutions[TPOP][12], int *tournamentelements, int tour){

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

void crossover(int solutions[TPOP][12], int parent1[10], int parent2[10], int number, int range){

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
            solutions[POP + range - 1][i] = parent2[i];
            solutions[POP + range][i] = parent1[i];
        }else{
            solutions[POP + range - 1][i] = parent1[i];
            solutions[POP + range][i] = parent2[i];
        }
    }

    calcnumbers(solutions[POP + range - 1]);
    calcnumbers(solutions[POP + range]);
    //print(solutions[100 + range - 1],11);
    //print(solutions[100 + range],11);
}


void quickSort(int solutions[TPOP][12], int comeco, int fim,int pos){
    int pivot,aux[12];
	int i, j;

	pivot = (comeco+fim)/2;
	i = comeco;
	j = fim;

	while(i <= j){
		while(solutions[i][pos] < solutions[pivot][pos])
			i++;

		while(solutions[j][pos] > solutions[pivot][pos])
			j--;

		if(i <= j){
			exchange(aux,solutions[i]);
			exchange(solutions[i],solutions[j]);
			exchange(solutions[j],aux);
			i++;j--;
        }
	}

	if(j > comeco)
		quickSort(solutions, comeco, j, pos);

	if(i < fim)
		quickSort(solutions, j+1, fim, pos);

}

void printmatrix(int solutions[180][12]){
    int i;
    printf("\n");
    for(i = 0; i < TPOP; i++){

        print(solutions[i],11);

    }
    printf("\n");

}

void exchange(int element1[12],int element2[12]){
    int i;

    for(i = 0; i < 12; i++){
        element1[i] = element2[i];
    }
}

int calctotal(int solutions[POP][12]){
    int i, resp = 0;

    for (i = 0; i < POP; i++) {
        resp += solutions[i][11];
    }

    return resp;
}

void elite(int solutions[TPOP][12]){

	int i, j, aux =((POP*ELITETX)/100);

    quickSort(solutions, 0, POP - 1, 10);
    for(i = POP; i < TPOP; i++){
        for(j = 0; j < 12; j++){
            solutions[i - POP + aux][j] = solutions[i][j];
        }
    }
}


void printconfiguration(int count, float time){

	float aux = 0;

	printf("\\item Configurações: \\\\ \n");
	printf(" 	Método de Seleção: \\\\ \n");
	if(OPTR == 0){
		printf(" 	Torneior com %d elementos \\\\ \n",TOUR);
	}
	else if(OPTR == 1){
		printf(" 	Roleta \\\\ \n");
	}
    else if(OPTR == 2){
        printf(" 	Torneior estocástico com %d elementos \\\\ \n",TOUR);
    }
	printf(" 	Crossover cíclico com taxa de %.0f\% \\\\ \n",((float(TCROS)/POP)*100));
	printf(" 	Mutação com taxa de %d \% \\\\ \n",PMUT);
	printf(" 	Método de reinserção: \\\\ \n");
	if(ELITE == 0){
		printf(" 	Reinserção ordenada(melhores entre pais e filhos) \\\\ \n");
	}
	else{
		printf(" 	Reinserção pura com elitismo de %d\% \\\\ \n",ELITETX);
	}

	aux = (float(count)*100)/EXPER;
	printf(" 	TAXA DE CONVERGÊNCIA: %.2f\% \\\\ \n",aux);
	printf("	TEMPO DE EXECUÇÃO: %.1f segundos \\\\ \n",time);
}
