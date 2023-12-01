#include <cstdio>
int main()
{
	unsigned short s[64], w, l;
	unsigned long long n, r;
	for (scanf("%llu", &n); n; n--)
	{
		scanf("%llu%hu", &r, &w);
		for (l = 0; r; r /= w)
			s[l++] = r % w;
		for (; l; l--)
			putchar(s[l - 1] + (s[l - 1] < 10 ? '0' : 'A'));
		putchar('\n');
	}
	return 0;
}
