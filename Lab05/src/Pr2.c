#include <math.h>
#include <stdbool.h>

int main(){
    unsigned int a = 7;
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
    return 0;
}
