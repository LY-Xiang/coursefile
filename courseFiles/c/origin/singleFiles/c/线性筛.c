#include <stdio.h>
void prime(int, unsigned *);
int main(void)
{
	unsigned p[100 + 1], i;
	prime(100, p);
	printf("100以内的素数有:");
	for (i = 1; i <= 100; i++)
		if (p[i] == 1)
			printf("%d ", i);
	return 0;
}

void prime(int n, unsigned *p)
{
	if (n >= 0)
		p[0] = 0;
	if (n >= 1)
		p[1] = 0;
	if (n >= 2)
		p[2] = 1;
	int i;
	for (i = 3; i <= n; i++)
		p[i] = i & 1;
	int j, pi[n], pn = 0, in = 0;
	for (i = 3; i <= n; i++)
	{
		if (p[i] == 1)
			pi[++pn] = i;
		in = n / i;
		for (j = 1; j <= pn && pi[j] <= in; j++)
		{
			p[i * pi[j]] = 0;
			if (i % pi[j] == 0)
				break;
		}
	}
	return;
}turn;
}