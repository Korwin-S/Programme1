int main(){
    int num = 28;
    int sum = 0;
    char result;
    for (int i = 1; i <= num / 2; i++){
        if (num % i == 0) sum += i;
    }
    if (sum == num) result = 'Y';
    else result = 'N';
    return 0;
}
