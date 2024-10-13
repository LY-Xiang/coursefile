#include <cstdio>
void pline(int, bool *);
int main(void)
{
	bool p[10000 + 1];
	pline(10000, p);
	printf("10000以内的素数有:");
	for (int i = 1; i <= 10000; i++)
		if (p[i])
			printf("%d ", i);
	return 0;
}

void pline(int n, bool *p) //线性筛
{
	if (n >= 0)
		p[0] = false;
	if (n >= 1)
		p[1] = false;
	if (n >= 2)
		p[2] = true;
	for (int i = 3; i <= n; i++)
		p[i] = i & 1;
	int pi[n], pn = 0, in = 0;
	for (int i = 3; i <= n; i++)
	{
		if (p[i])
			pi[++pn] = i;
		in = n / i;
		for (int j = 1; j <= pn && pi[j] <= in; j++)
		{
			p[i * pi[j]] = false;
			if (i % pi[j] == 0)
				break;
		}
	}
	return;
}