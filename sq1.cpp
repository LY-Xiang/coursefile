#include <cstdio>
int main()
{
    char ch;
    for (ch = getchar(); ch < '0' || '9' < ch; ch = getchar())
        ;
    if (ch != '1' && ch != '0' || getchar() != ' ')
    {
        putchar('n');
        putchar('o');
        return 0;
    }
    for (ch = getchar(); ch < '0' || '9' < ch; ch = getchar())
        ;
    if (ch != '1' && ch != '0')
    {
        ch = getchar();
        if ('0' <= ch && ch <= '9')
        {
            putchar('n');
            putchar('o');
            return 0;
        }
        else
        {
            putchar('y');
            putchar('e');
            putchar('s');
            return 0;
        }
    }
    else
    {
        putchar('n');
        putchar('o');
        return 0;
    }
    return -1;
}