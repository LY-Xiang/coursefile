#include <cstdio>
typedef signed long long LLD;
template <class T>
void exgcd(T, T, T &, T &);
int main()
{
	LLD n, a = 0, i, x, y;
	const LLD m = 998244353;
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &y);
		a = (a + y) % m;
	}
	exgcd<LLD>(n, m, x, y);
	x = (x % m + m) % m * a % m;
	for (i = 1; i <= n; i++)
	{
		printf("%lld ", i * x % m);
	}
	return 0;
}
template <class T>
void exgcd(T a, T b, T &x, T &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
	}
	else
	{
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
	return;
}n;
}