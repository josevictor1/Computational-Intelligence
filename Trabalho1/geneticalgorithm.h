#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>


int mypow(int number, int expoent);
//void calcnumbers(int *vet, int *resultcalculated, int *expectedresult); First Version
void calcnumbers(int *vet);
bool verify(int vet[12], int number, int range);
void percentage(int solutions[100][12], float qtd[10]);
int maxelement(int solutions[100][12], int *tournamentelements, int tour);
