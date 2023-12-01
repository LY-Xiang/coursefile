#include <stdio.h>
int main()
{
	int s = 0, n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		s += i % 2 == 0 | i % 3 == 0 || i % 5 == 0;
		printf("%d %d\n", (i / 2) + (i + 3) / 6 + (i + 5) / 30 + (i + 25) / 30, s);
	}
	return 0;
}