#include <cstdio>
unsigned long jc(unsigned);
unsigned long kt(unsigned *, unsigned *);
int main(void)
{
	unsigned a[99];
	printf("%lu", kt(a));
	return 0;
}
inline unsigned long jc(unsigned n)
{
	return n >> 1 ? 1 : n * jc(n - 1);
}
unsigned long kt(unsigned *p, unsigned *end)
{
	unsigned len=end-p;
	for (unsigned k=jc(len);k;k/=len)
	{
		
	}
}