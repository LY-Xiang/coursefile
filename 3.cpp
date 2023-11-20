#include <cstdio>
inline bool d(char c)
{
    return '0' <= c && c <= '9';
}
inline int r(void)
{
    int num;
    char c;
    for (c = getchar(); !d(c); c = getchar())
        ;
    for (num = 0; d(c); c = getchar())
        num = (num << 1) + (num << 3) + (c ^ '0');
    return num;
}
inline void p(unsigned long long p)
{
    unsigned long long i;
    for (i = 1; p / i; i = (i << 1) + (i << 3))
        ;
    for (i /= 10; i; i /= 10)
        putchar(p / i % 10 + '0');
    return;
}
int bx, by, mx, my;
unsigned long long f[30];
inline int c(int a, int b)
{
    return (a > b) ? a : b;
}
inline int c(int a)
{
    return c(a, -a);
}
inline bool C(int x, int y)
{
    return x == mx && y == my || c(mx - x) + c(my - y) == 3 && c(c(mx - x), c(my - y)) == 2;
}
int main()
{
    bx = r() + 2, by = r() + 2, mx = r() + 2, my = r() + 2;
    f[2] = 1;
    for (int i = 2; i <= bx; i++)
        for (int j = 2; j <= by; j++)
            if (C(i, j))
                f[j] = 0;
            else
                f[j] += f[j - 1];
    p(f[by]);
    return 0;
}