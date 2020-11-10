int main()
{
    int k = 8;
    int m = 4;
    int n = 0;
    int a = 0;
        if (k >= m){
            a = k;
            k = m;
            m = a;
        }
        if (k >= n){
            a = k;
            k = n;
            n = a;
        }
        if (m >= n){
            a = m;
            m = n;
            n = a;
        }
	return 0;
}
