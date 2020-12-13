#include <stdlib.h>
#include <time.h>

int calculation (int a, int b){
    while (a != 0 && b != 0){
        if (a > b) a = a % b;
        else b = b % a;
    }
    return a+b;
}

int main(){
    const int num1 = 175;
    const int num2 = 250;
    int result = 0, result_rand = 0;
    srand(time(NULL));
    result = calculation (num1, num2);
    result_rand = calculation (rand()%500, rand()%500);
    return 0;
}