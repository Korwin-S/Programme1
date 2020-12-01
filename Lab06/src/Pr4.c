#include <string.h>

int main()
{
	char str[] = " Cogito ergo    sum  ";
	char *s = " ";
	strncat (str, s, 1);
	int sum = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != ' ' && str[i+1] == ' ') {sum += 1;};
	}
    return 0;
}
