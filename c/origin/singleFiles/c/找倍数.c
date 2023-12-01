#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", n / 2 + (n + 3) / 6 + (n + 5) / 30 + (n + 25) / 30);
	return 0;
}