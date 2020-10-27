int main() 
{
    int a = 254;
	int result = ((a % 10) * 100) + (((a % 100) / 10) * 10) + (a / 100);
	return 0;
}
