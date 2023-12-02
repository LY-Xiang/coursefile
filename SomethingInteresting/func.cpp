#include <cstdio>
class bop
{
	int n[4];

  public:
	bop(int a, int b)
	{
		n[0] = a + b;
		n[1] = a - b;
		n[2] = a * b;
		n[3] = a / b;
	}
	bop* operator()(void)
	{
		return this;
	}
};
int main()
{
	int a[4] = {0};
	a = bop(7, 2)();
	printf("%d%d%d%d", a[0], a[1], a[2], a[3]);
	return 0;
}
urn 0;
}
