#include <string.h>

char shl(int N, char res[N+1]){
    char str[N+1];
    for (int i = 0; i <= N; i++) str[i] = res[i];
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i+1] == '\0'){res[i] = ' '; res[i+1] = '\0'; break;}
        else res[i] = str[i+1];
    }
    return 0;
}

char shr(int N, char res[N+1]){
    char str[N+1];
    for (int i = 0; i <= N; i++) str[i] = res[i];
    res[0] = ' ';
    for (int i = 0; str[i] != '\0'; i++) {
        res[i+1] = str[i];
        if (str[i+1] == '\0'){res[i+1] = '\0'; break;}
    }
    return 0;
}

int main()
{
    	int N = 0;
        char filler = '_';
    	char str[] = " Ivanov Vasiliy   ";
    	int c1 = 0;
    	int c2 = 0;
    	for (int i = 0; str[i] != '\0'; i++) {
                N += 1;
            }
        char res[N+1];
        for (int i = 0; i <= N; i++) {
                res[i] = ' ';
            }
        res[N] = '\0';
    	if (str[0] == ' '){
            c1 += 1;
            for (int i = 1; str[i] == ' '; i++) {
                c1 += 1;
            }
    	}
    	else c1 = 0;

    	if (str[N - 1] == ' '){
            c2 += 1;
            for (int i = N - 2; str[i] == ' '; i--) {
                c2 += 1;
            }
    	}
    	else c2 = 0;
        int c3 = 0;

        for (int i = 0; i < N; i++) res[i] = str[i];

        if (c1 > c2){
            c3 = (c1 - c2) / 2;
            for (int i = 0; i < c3; i++) {
                shl(N, res);
            }
        } else if (c1 < c2){
            c3 = (c2 - c1) / 2;
            for (int i = 0; i < c3; i++) {
                shr(N, res);
            }
        } /*else if (c1 == c2){
            for (int i = 0; i < N; i++) {
                res[i] = str[i];
            }
        }*/
        for (int i = 0; res[i] == ' '; i++) {
                res[i] = filler;
            }
        for (int i = N - 1; res[i] == ' '; i--) {
                res[i] = filler;
            }
    	return 0;
}
