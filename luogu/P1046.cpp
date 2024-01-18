#include <cstdio>
int main()
{
    unsigned short n, i, l[10], s = 0;
    for (i = 0; i < 10; i++)
        scanf("%hu", l + i);
    scanf("%hu", &n);
    n += 30;
    for (i = 0; i < 10; i++)
        s += n >= l[i];
    printf("%hu", s);
    return 0;
}