#include <cstdio>
int main()
{
    unsigned short n, i, j, k = 0;
    scanf("%hu", &n);
    for (i = n; i; i--)
    {
        for (j = i; j; j--)
            printf("%02hu", ++k);
        putchar('\n');
    }
    return 0;
}
