#include <cstdio>
int main()
{
	unsigned short s[64], *w, W, l;
	unsigned long long n, i, *r, R;
	scanf("%llu", &n);
	w = new unsigned short[n];
	r = new unsigned long long[n];
	for (i = 0; i < n; i++)
		scanf("%llu%hu", r + i, w + i);
	for (i = 0; i < n; i++)
	{
		R = r[i];
		W = w[i];
		for (l = 0; R; R /= W)
			s[l++] = R % W;
		for (; l; l--)
			putchar(s[l - 1] + (s[l - 1] < 10 ? '0' : 'A'));
		putchar('\n');
	}
	return 0;
}