#include <cstdio>
int main(void)
{
	float h;
	unsigned short n;
	scanf("%f%hu", &h, &n);
	float ans = h;
	for (n--; n; n--)
	{
		ans += h;
		h /= 2;
	}
	printf("%.4f", ans);
	return 0;
}4f",ans/1000000.0 );
	return 0;
}