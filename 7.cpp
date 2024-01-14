#include <cstdio>
#include <algorithm>
int main()
{
	const int MAXN = 10000;
	int n, q, data[MAXN + 1] = {0}, x, max = 1, i;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", data + i);
		data[0] += data[i];
	}
	std::sort(data + 1, data + n + 1, [](int a, int b) { return a > b; });
	while (q--)
	{
		scanf("%d", &x);
		if (x > data[0])
			printf("%d\n", -1);
		else if (x <= data[max]) //max前存累计糖果,max后存单独糖果
			printf("%d\n", int(std::lower_bound(data + 1, data + max + 1, x) - data));
		else
		{
			for (i = max + 1; data[i - 1] < x; i++)
				data[i] += data[i - 1];
			printf("%d\n", (max = i - 1));
		}
	}
	return 0;
}
