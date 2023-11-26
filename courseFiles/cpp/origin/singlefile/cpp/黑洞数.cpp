#include<cstdio>
using namespace std;
const int MAX=2147483647;
int xmin(int x);
int xmax(int x);
int main()
{
    int tot=0;
    for (int x=1;x<=MAX;x++)
        if (xmax(x)-xmin(x)==x)
        {
            tot++;
            printf("%d:%d-%d=%d\r\n",tot,xmax(x),xmin(x),x);
        }
        return 0;
}
int xmin(int x)
{
    int a[10]={0},ans=0;
    while (x!=0)
    {
        a[x%10]++;
        x/=10;
    }
    for (int i=0;i<=9;i++)
        for (int j=1;j<=a[i];j++)
            ans=ans*10+i;
    return ans;
}
int xmax(int x)
{
    int a[10]={0},ans=0;
    while (x!=0)
    {
        a[x%10]++;
        x/=10;
    }
    for (int i=9;i>=0;i--)
        for (int j=1;j<=a[i];j++)
            ans=ans*10+i;
    return ans;
}