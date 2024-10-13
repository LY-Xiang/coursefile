#include <bitset>
#include <cstdio>
int main()
{
	unsigned long long n, ans = 1;short i;
	scanf("%llu", &n);
	std::bitset<64> bit(n);
	for (i = 63; i + 1 && !bit[i]; i--);
	for (i--; i + 1; i--)ans <<= ~bit[i];
	printf("%llu", ans - 1);
	return 0;
}