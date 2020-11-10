#define PI 3.14

int main()
{	
    float s, v, l, result = 0.0;
    char command = 'v';
    float r = 9.0;
    if (command == 'l'){
        result = 2.0 * PI * r;
    	}
    if (command == 's'){
        result = PI * r * r;
    	}
    if (command == 'v'){
         result = 4.0 / 3.0 * PI * r * r * r;
    	}
    return 0;
}
