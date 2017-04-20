#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>


int mypow(int number, int expoent);// calculate the expoent
//void calcnumbers(int *vet, int *resultcalculated, int *expectedresult); First Version
void calcnumbers(int *vet);
bool verify(int vet[12], int number, int range); // verify whether the number is equal to another number in the int array
void percentage(int solutions[100][12], float qtd[10]);// return the percentage of a number im the solutions
int maxelement(int solutions[100][12], int *tournamentelements, int tour); // Return the index of the maximum element
int minelement(int solutions[100][12], int *tournamentelements, int tour); // Return the index of the minimum element
int calctcross_int(int population, int percentage);// calculate the numbers of parents to the cross over
int search(int vet[10], int value); // realize the search in the array of integers
void print(int *vet,int n);
void crossover(int solutions[180][12], int parent1[10], int parent2[10], int number, int range);
void quickSort(int solutions[180][12],int *vetor, int comeco, int fim);
