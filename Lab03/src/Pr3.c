int main() 
{
	double true_a = 2;
	double a, b, c, d, e;
	a = true_a;
	a = a * a;
	a *= a;//a^4
	
	a = true_a;
	a *= a;
	b = a * a;
	a *= b;//a^6
	
	a = true_a;
	a *= a;
	a *= a;
	a *= a;//a^8
	
	a = true_a;
	c = a * a;
	d = c * c;
	e = d * c;
	a = e * d;//a^10
	return 0;
}
