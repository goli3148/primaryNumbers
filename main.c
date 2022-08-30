//0.421 seconds to find 78,497 prime number out of 1,000,000
//1.893 seconds to find 664,578 prime numbers out of 10,000,000
//26.687 seconds to find 5,761,454 prime nubers out of 100,000,000
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

const int min = 4;
const int max = 100000010;
const int len = 100000000;

int index;
int *primary;

void Show(){
    int i = 0;
    for (; i<len; i++){
        if (primary[i]==1)
            break;
        printf("%d:%d\t", i, primary[i]);
        if (i%10==0)
            printf("\n");
    }
}
void Show2(){
    int i = 0;
    for (; i<len && primary[i] != 1; i++);
    i--;
    printf("%d:%d\n", i, primary[i]);
}

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

int Feasible(int num){ 
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
    if (len>10000){
        Show2();
        return;
    }
    Show();
}

int main(){
    Algorithm();
    return 0;
}