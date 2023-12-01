#include<cstdio>
using namespace std;
int main()
{
    int n,x,a=0;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        int t=i;
        while(t!=0)
        {
            a+=(t%10==x)?(1):(0);
            t/=10;
        }
    }
    printf("%d",a);
    return 0;
}