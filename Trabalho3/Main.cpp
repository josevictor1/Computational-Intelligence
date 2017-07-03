
#include "Neuron.h"

#define TYPEW 0 
#define NEURONRANGE 6
#define NUMBERRANGE 6 /*exercise 1 - 2*/
#define NUMBERTESTRANGE 6
#define DISTORTIONRANGE 6
#define WITHLETTERS 1

int main(int argc, char const *argv[]){


    Number number[6];
    Neuron neuron[6];
    
    for(size_t i = 0; i < 6; i++){
        number[i].setNumber(i);
        number[i].choiceRepresentation();
        neuron[i].setRecognize(i);
        neuron[i].setWeight(TYPEW);
    }

    int  epoc, total = 0;

/*
    int u = 0, y = 0;
    u = neuron[0].sigma(number[0]);
    cout<< "u:" <<u << endl;
    y = neuron[0].limiar(u);
    cout<< "y:" <<y << endl;
*/
    /*first experiment*/
    
    //for(size_t i = 0; i < 6; i++)
        
    cout<<"\n";
    cout << "Numeros ensaiados" <<endl;
    for(size_t i = 0; i < NEURONRANGE; i++){
        //for(size_t j = 0; j < NUMBERRANGE; j++){
            //number[i].printNumber();
            //cout << number[j].getNumber()<< " ";
            epoc = neuron[i].calculate(number,NUMBERRANGE);
            total+=epoc;       
        //}
        cout<<"Numero de epocas para o neurônio " << i <<": "<< epoc <<endl;
    }
    cout<<"Numero total de epocas:"<< total <<endl;
    /*Result verification*/
    cout<<"Numero verificado:"<<endl;
    for(size_t i = 0; i < NEURONRANGE; i++){
        for(size_t j = 0; j < NUMBERTESTRANGE; j++){
            cout << number[j].getNumber()<< " ";
            //number[j].printNumber();
            neuron[i].verify(number[j]);

        }
    }

    for(size_t i = 0; i < NEURONRANGE;i++){
        cout << " Neuronio: "<< i << endl;
        cout << "W: ";
        neuron[i].getWeight();
        /*for(size_t j = 0; j < 6; j++){
            neuron[].getWeight();
        }*/
        cout << endl;
    }
    
    for(size_t i = 0; i < DISTORTIONRANGE; i++){
        for(size_t j = 0; j < NEURONRANGE; j++){
            cout<< "Neuronio: "<< j <<endl;
            if(WITHLETTERS == 0){
                for(size_t k = 0; k < 10; k++){
                    Number aux = number[i];
                    aux.generateModifications(k);
                    //aux.printNumber();
                    cout << k <<" Distorção do número: " << aux.getNumber();
                    neuron[j].verify(aux);
                }
            }
            else{
                Number aux = number[i];
                aux.setWithLetter(i);
                aux.printNumber();
                aux.setNumber(i+7);
                neuron[j].verify(aux);
            }
        }
    }
    

}