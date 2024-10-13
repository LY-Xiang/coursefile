#include <cstdio>
#include <cmath>
void print(unsigned long long);
int main()
{
	unsigned long long n = 0, i = 2;
	bool b = false;
	for (char ch = '0'; '0' <= ch && ch <= '9'; ch = getchar())
		n = n * 10 + ch - '0';
	for (; i * i <= n; i++)
		if (n % i == 0)
		{
			b = true;
			print(i);
			break;
		}
	for (; i * i <= n; i++)
		for (; n % i == 0; n /= i)
		{
			putchar('*');
			print(i);
		}
	if (n >> 1)
	{
		if (b)
			putchar('*');
		print(n);
	}
	return 0;
}
inline void print(unsigned long long i)
{
	unsigned long long j = 0;
	for (; i; i /= 10)
		j = j * 10 + i % 10;
	for (; j; j /= 10)
		putchar(j % 10 + '0');
	return;
}