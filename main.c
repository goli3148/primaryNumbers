#include "stdio.h"
#include "stdlib.h"
#include "math.h"

const int min = 4;
const int max = 1000000;
const int len = 1000000;

int index;
int *primary;

void Initialize(){
    primary = (int*)malloc(len * sizeof(int));
    int i = 0;
    for (;i<len;i++){
        primary[i] = 1;
    }
    primary[0] = 2;
    primary[1] = 3;
    index = 2;
}

int Feasible(int num){ //0.421 second to find 78,497 prime number out of 1,000,000
    int result = sqrt(num), i = 0;
    for (;i<=index && result>=primary[i]; i++){
        if (num % primary[i] == 0)
            return 0; //it is not feasible to be primary
    }
    return 1; // it is feasible to be primary
}

void Algorithm(){
    Initialize();
    int counter = min;
    if (counter%2==0)
        counter ++;
    for (;counter<=max && index<len ; counter+=2){
        if (Feasible(counter) == 1){
            primary[index] = counter;
            index ++; 
        }
    }
}
void Show(){
    int i = 0;
    for (; i<len; i++){
        printf("%d:%d\t", i, primary[i]);
        if (i%10==0)
            printf("\n");
        if (primary[i]==1)
            break;
    }
}
int main(){
    Algorithm();
    Show();
    return 0;
}