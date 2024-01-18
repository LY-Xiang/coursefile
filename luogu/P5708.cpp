#include <cstdio>
#include <cmath>
int main()
{
    float a, b, c, p;
    scanf("%f%f%f", &a, &b, &c);
    p = (a + b + c) / 2;
    printf("%.01f", sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}