int main() 
{
	int num = 1111;
	int notation = 8;
	int result = (num % 10) + notation * ((num % 100) / 10) + notation * notation * ((num % 1000) / 100) + notation * notation * notation * (num / 1000);
	return 0;
}
