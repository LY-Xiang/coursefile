#include <cstdio>
int main()
{
    char ch, op;
    long long a = 0, b = 0;
    for (ch = getchar(); ch < '0' || '9' < ch; ch = getchar())
        ;
    for (; '0' <= ch && ch <= '9'; ch = getchar())
        a = (a << 1) + (a << 3) + ch - '0';
    for (op = ch; op != '+' && op != '-' && op != '*' && op != '/'; op = getchar())
        ;
    for (ch = getchar(); ch < '0' || '9' < ch; ch = getchar())
        ;
    for (; '0' <= ch && ch <= '9'; ch = getchar())
        b = (b << 1) + (b << 3) + ch - '0';
    switch (op)
    {
    case '+':
        printf("%lld+%lld=%lld", a, b, a + b);
        break;
    case '-':
        printf("%lld-%lld=%lld", a, b, a - b);
        break;
    case '*':
        printf("%lld*%lld=%lld", a, b, a * b);
        break;
    case '/':
        printf("%lld/%lld=%lld......%lld", a, b, a / b, a - a / b * b);
        break;
    default:
        printf("Wrong operation!");
        break;
    }
    return 0;
}