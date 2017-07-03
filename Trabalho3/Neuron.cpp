
#include "Neuron.h"


void Neuron::setRecognize(int recognize){
    this->recognize = recognize;
}

int Neuron::getRecognize(){
    return this->recognize;
}

void Neuron::setWeight(int op){
    default_random_engine generator;
    uniform_real_distribution<double> negativeone_to_one(-1,1.0);
    if(op == 0){
        for(size_t i = 0; i < 31; i++)
            this->weight[i] = 0;
    }
    else{
        for(size_t i = 0; i < 31; i++){
            //int option = random()%3;
            double value = negativeone_to_one(generator);
            while(value > 1){
                value = negativeone_to_one(generator);
            }
            //cout <<"option value: " << option;            
            this->weight[i] = value;
        }
    } 
}

void Neuron::getWeight(){
    for(size_t i = 0; i < 31; i++)
        cout<< this->weight[i] << " ";
}

double Neuron::sigma(Number number){
    double result = 0, *representation = number.getRepresentation();

    for(size_t i = 0; i < 31; i++){
        result += representation[i]*weight[i];
    }
    return result;
}

int Neuron::limiar(double u){
    return u >=1 ? 1 : 0;
}

void Neuron::verify(Number number){
    double u = 0;
    int y = 0;
    u = sigma(number);
    y = limiar(u);
    if((number.getNumber() != this->recognize && y == 1)){
        cout <<" The answer is wrong: the answer is greatter than the correct "<< endl;
    }
    else if((number.getNumber() == this->recognize && y == 0)){
        cout <<" The answer is wrong: the answer is smaller than the correct "<< endl;
    }
    else{
        cout <<" The answer is correct: "<< y << endl;
    }
}

int Neuron::calculate(Number number[6], int range){

    int epoc = 0, count = 0, y = 0;
    double u = 0;
    while(count < range){

        for(size_t i = 0; i < range; i++){
            u = sigma(number[i]);
            y = limiar(u);
            if(number[i].getNumber() != this->recognize && y == 1){
                double *representation = number[i].getRepresentation();
                //cout << "passou " <<endl;
                for(size_t j = 0; j < ENTRYS; j++){    
                    this->weight[j] -= representation[j];
                }
                /*for(size_t j = 0; j < ENTRYS; j++){
                    cout <<weight[j] <<endl;
                }*/
                count = 0;
            }
            else if(number[i].getNumber() == this->recognize && y == 0){
                double *representation = number[i].getRepresentation();
                //cout << "passou 2" <<endl;
                for(size_t j = 0; j < ENTRYS; j++){
                    this->weight[j] += representation[j];
                }
                count = 0;
            }
            else{
                count++;
            }
        }
        epoc++;
    }
    return epoc;
}



