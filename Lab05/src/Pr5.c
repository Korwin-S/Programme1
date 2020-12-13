#define NUM 0.5

double f (double x) {
    double y = 0;
    y = NUM - x * x;
    return y;
   }

double calculation (double a, double b, double eps){
    double c;
    while ((b - a) / 2 > eps){
         c = (a + b) / 2;
         if ((f(a) * f(c)) > 0) a = c;
         else b = c;
        }
    return c;
}

int main (){
   double eps = 0.001;
   double result = 0;
   char error = '0';
   double a = 0;
   double b = 0;

   if (NUM >= 1) b = NUM;
   else if (NUM < 1 && NUM > 0) b = NUM + 1;
   else error = 'E';

   result = calculation (a, b, eps);
   return 0;
}