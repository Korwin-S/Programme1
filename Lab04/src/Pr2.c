int main()
{
    const float num = 228.228;
    float num1 = num;
    num1 = (int) num1; //целая часть
    int fraction = num * 1000;  
    fraction = fraction % 1000;	//дробная часть
    float result = 0.0;
    char error;
    if (fraction == 0 || num1 == 0){
        error = 'E';
    }
    else {
        result = fraction / num1;
        result = result * 100;
        result = (int) result;
        result = (float) result;
        result = result / 100;
    }
    return 0;
}
