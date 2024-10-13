#include<cstdio>
using namespace std;
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    float s=(float)(x)/(float)(y);
    printf("x/y=%f\r\nPress any key to continue",s);
    getchar();
    return 0;
}