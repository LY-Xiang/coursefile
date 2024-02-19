#include <cstdio>
int main(void)
{
	//freopen("fill.in","r",stdin);
	//freopen("fill.out","w",stdout);
	unsigned f[100001] = {1, 1}, t, i;
	scanf("%u", &t);
	for (i = 2; i <= 100000; i++)
	{
		f[i] = (f[i - 1] + 2 * f[i - 2]) % 100007;
		printf("%u,", f[i]);
	}
	for (i = t; i; i--)
	{
		scanf("%u", &t);
		printf("%u\n", f[t]);
	}
	return 0;
}