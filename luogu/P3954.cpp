#include <cstdio>
int main()
{
    unsigned short a, b, c;
    scanf("%hu%hu%hu", &a, &b, &c);
    printf("%hu", (a * 2 + b * 3 + c * 5) / 10);
    return 0;
}