int main(){
    int num = 228912;
 //   if (num < 0) num = -num;
    char result;
    int sum1 = num / 100000 + (num / 10000) % 10 + (num / 1000) % 10;
    int sum2 = (num / 100) % 10 + (num / 10) % 10 + num % 10;
    if (sum1 == sum2) result = 'Y';
    else result = 'N';
    return 0;
}
