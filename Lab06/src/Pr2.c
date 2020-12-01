#include <math.h>
#include <stdbool.h>

int prime(unsigned int a){
    char result;
    if (a < 1) result = 'N';
    else {
        int sqrt_a = sqrt(a) + 1;
        bool flag = true;
        for (int i = 2; i < sqrt_a; i++){
            if (a % i == 0){
                flag = false;
                break;
            }
        }
        if (flag == true) result = 'Y';
        else result = 'N';
    }
    return result;
}

int main(){
    const int max_size = 10000;
    int arr[max_size];
    int N = 9;
    int j = 1;
    for (int i = 0; i < N; i++){
        while (true){
            j += 1;
            if (prime(j) == 'Y'){
                arr[i] = j;
                break;
            }
        }
    }
    return 0;
}
