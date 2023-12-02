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
	bop *operator()(void)
	{
		return this;
	}
} a(7, 2);
int main()
{
	a *b[4];
	printf("%d%d%d%d", b[0], b[1], b[2], b[3]);
	return 0;
}
]);
	return 0;
}
urn 0;
}
