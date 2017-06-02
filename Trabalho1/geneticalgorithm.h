#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <list>
#include <string.h>

#define POP 50
#define TCROS int(POP*0.8)
#define TPOP POP + TCROS
#define PMUT 50
#define NGEN 200
#define NELEMENT 10
#define EXPER 1000
#define TOUR 3
#define MAXFIT 6 // values: 100000(to normal fit), 5(to MONEY, APPLE and OASIS), 6(to DANGER and ROBERT)
#define OPTR 1
#define ELITE 1
#define ELITETX 20
#define QTDMUT 2
#define CRIPTOPT 4
#define TYPEFIT 1

int mypow(int number, int expoent);// calculate the expoent
//void calcnumbers(int *vet, int *resultcalculated, int *expectedresult); First Version
void calcnumbers(int *vet);
bool verify(int vet[12], int number, int range); // verify whether the number is equal to another number in the int array
void percentage(int solutions[TPOP][12], float qtd[10]);// return the percentage of a number im the solutions
int maxelement(int solutions[TPOP][12], int *tournamentelements, int tour); // Return the index of the maximum element
int minelement(int solutions[TPOP][12], int *tournamentelements, int tour); // Return the index of the minimum element
int calctcross_int(int population, int percentage);// calculate the numbers of parents to the cross over
int search(int vet[10], int value); // realize the search in the array of integers
void print(int *vet,int n);
void crossover(int solutions[TPOP][12], int parent1[10], int parent2[10], int number, int range);
//void quickSort(int solutions[TPOP][12],int *vetor, int comeco, int fim);
void quickSort(int solutions[TPOP][12], int comeco, int fim,int pos);
void printmatrix(int solutions[TPOP][12]);
void cleanarray(int *vet, int n);
void exchange(int element1[12],int element2[12]);
int calctotal(int solutions[POP][12]);
void elite(int solutions[TPOP][12]);
void printconfiguration(int count,float time);
