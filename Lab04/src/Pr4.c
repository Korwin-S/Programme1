int main()
{
    float x = 2.0;
    float y = 0.0;
    if ( x < -1){
        y = -1.0 / x;
    }
    if (x >= -1 && x <= 1){
        y = x * x;
    }
    if (x > 1){
        y = 1.0;
    }
    return 0;
}
