#include <stdarg.h>

int calculation (int size, ... )
{
    int result = 0;
    int i = 1;
    va_list v;
    va_start(v, size);
    int a = va_arg(v, int), b;
    while (i < size){
        b = va_arg(v, int);
        if (a < b) result += 1;
        a = b;
        i++;
    }
    va_end(v);
    return result;
}

int main()
{
    int size = 9;
    int result = calculation(size, 2, 2, 8, 7, 9, 3, 12, 5, 99);
    return 0;
}

