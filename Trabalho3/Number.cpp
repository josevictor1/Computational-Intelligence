#include <iostream>
#include "Number.h"


Number::Number(int option){

    switch(option){
        case 0:
            representation[0] = 1;
            representation[1] = 0;//begin line
            representation[2] = 1;
            representation[3] = 1;
            representation[4] = 1;
            representation[5] = 0;//end line
            representation[6] = 1;//begin line
            representation[7] = 0;
            representation[8] = 0;
            representation[9] = 0;
            representation[10] = 1;//end line
            representation[11] = 1;//begin line
            representation[12] = 0;
            representation[13] = 0;
            representation[14] = 0;
            representation[15] = 1;//end line
            representation[16] = 1;//begin line
            representation[17] = 0;
            representation[18] = 0;
            representation[19] = 0;
            representation[20] = 1;//end line
            representation[21] = 1;//begin line
            representation[22] = 0;
            representation[23] = 0;
            representation[24] = 0;
            representation[25] = 1;//end line
            representation[26] = 0;//begin line
            representation[27] = 1;
            representation[28] = 1;
            representation[29] = 1;
            representation[30] = 0;//end line
            break;
        case 1:
            representation[0] = 1;
            representation[1] = 0;//begin line
            representation[2] = 0;
            representation[3] = 1;
            representation[4] = 0;
            representation[5] = 0;//end line
            representation[6] = 0;//begin line
            representation[7] = 1;
            representation[8] = 1;
            representation[9] = 0;
            representation[10] = 0;//end line
            representation[11] = 0;//begin line
            representation[12] = 0;
            representation[13] = 1;
            representation[14] = 0;
            representation[15] = 0;//end line
            representation[16] = 0;//begin line
            representation[17] = 0;
            representation[18] = 1;
            representation[19] = 0;
            representation[20] = 0;//end line
            representation[21] = 0;//begin line
            representation[22] = 0;
            representation[23] = 1;
            representation[24] = 0;
            representation[25] = 0;//end line
            representation[26] = 1;//begin line
            representation[27] = 1;
            representation[28] = 1;
            representation[29] = 1;
            representation[30] = 1;//end line
            break;
        case 2:
            representation[0] = 1;
            representation[1] = 0;//begin line
            representation[2] = 1;
            representation[3] = 1;
            representation[4] = 1;
            representation[5] = 0;//end line
            representation[6] = 0;//begin line
            representation[7] = 1;
            representation[8] = 0;
            representation[9] = 1;
            representation[10] = 0;//end line
            representation[11] = 0;//begin line
            representation[12] = 0;
            representation[13] = 0;
            representation[14] = 1;
            representation[15] = 0;//end line
            representation[16] = 0;//begin line
            representation[17] = 0;
            representation[18] = 1;
            representation[19] = 0;
            representation[20] = 0;//end line
            representation[21] = 0;//begin line
            representation[22] = 1;
            representation[23] = 0;
            representation[24] = 0;
            representation[25] = 0;//end line
            representation[26] = 1;//begin line
            representation[27] = 1;
            representation[28] = 1;
            representation[29] = 1;
            representation[30] = 1;//end line
            break;
        case 3:
            representation[0] = 1;
            representation[1] = 0;//begin line
            representation[2] = 1;
            representation[3] = 1;
            representation[4] = 1;
            representation[5] = 1;//end line
            representation[6] = 0;//begin line
            representation[7] = 0;
            representation[8] = 0;
            representation[9] = 0;
            representation[10] = 1;//end line
            representation[11] = 0;//begin line
            representation[12] = 1;
            representation[13] = 1;
            representation[14] = 1;
            representation[15] = 1;//end line
            representation[16] = 0;//begin line
            representation[17] = 0;
            representation[18] = 0;
            representation[19] = 0;
            representation[20] = 1;//end line
            representation[21] = 0;//begin line
            representation[22] = 0;
            representation[23] = 0;
            representation[24] = 0;
            representation[25] = 1;//end line
            representation[26] = 0;//begin line
            representation[27] = 1;
            representation[28] = 1;
            representation[29] = 1;
            representation[30] = 1;//end line
            break;
        case 4:
            representation[0] = 1;
            representation[1] = 1;//begin line
            representation[2] = 0;
            representation[3] = 0;
            representation[4] = 1;
            representation[5] = 0;//end line
            representation[6] = 1;//begin line
            representation[7] = 0;
            representation[8] = 0;
            representation[9] = 1;
            representation[10] = 0;//end line
            representation[11] = 1;//begin line
            representation[12] = 0;
            representation[13] = 0;
            representation[14] = 1;
            representation[15] = 0;//end line
            representation[16] = 1;//begin line
            representation[17] = 1;
            representation[18] = 1;
            representation[19] = 1;
            representation[20] = 0;//end line
            representation[21] = 0;//begin line
            representation[22] = 0;
            representation[23] = 0;
            representation[24] = 1;
            representation[25] = 0;//end line
            representation[26] = 0;//begin line
            representation[27] = 0;
            representation[28] = 0;
            representation[29] = 1;
            representation[30] = 0;//end line
            break;
        case 5:
            representation[0] = 1;
            representation[1] = 0;//begin line
            representation[2] = 1;
            representation[3] = 1;
            representation[4] = 1;
            representation[5] = 1;//end line
            representation[6] = 0;//begin line
            representation[7] = 1;
            representation[8] = 0;
            representation[9] = 0;
            representation[10] = 0;//end line
            representation[11] = 0;//begin line
            representation[12] = 1;
            representation[13] = 1;
            representation[14] = 1;
            representation[15] = 1;//end line
            representation[16] = 0;//begin line
            representation[17] = 0;
            representation[18] = 0;
            representation[19] = 0;
            representation[20] = 1;//end line
            representation[21] = 0;//begin line
            representation[22] = 0;
            representation[23] = 0;
            representation[24] = 0;
            representation[25] = 1;//end line
            representation[26] = 0;//begin line
            representation[27] = 1;
            representation[28] = 1;
            representation[29] = 1;
            representation[30] = 1;//end line
            break;
    }

}
Number::setRepresentation(int representation[31]){
    for(size_t i; i < 31; i++){
        this.representation[i] = representation[i];
    }
}
Number::getRepresentation(){
    return representation;
}
Number::setWeigt(int weight[31]){
    for(size_t i; i < 31; i++){
        this.weight[i] = weight[i];
    }
}
Number::getWeight(){
    return weight;
}