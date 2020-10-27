int main() 
{
	int a = 549;
	float result1 = (float) (a / 100) / (a % 10);
	result1 = (float) result1 * 100;
	int result2 = (int) result1;
	float result3 = (float) result2;
	result3 = result3 / 100;
	return 0;
}
