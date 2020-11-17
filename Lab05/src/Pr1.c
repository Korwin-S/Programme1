int main(){
    const int num1 = 175;
    const int num2 = 250;
    int a = num1;
    int b = num2;
    int result = 0;
    while (a != 0 && b != 0){
        if (a > b) a = a % b;
        else b = b % a;
    }
    result = a + b;
  return 0;
}
