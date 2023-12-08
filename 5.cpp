#include <cstdio>
typedef unsigned long long LLU;
void exgcd(LLU,LLU,LLU&,LLU&);
int main(void)
{
	LLU n,a=0,i,t,x,y;
	const unsigned long long m=998244353;
	scanf("%llu",&n);
	for(i=0;i<n;i++)
	{
		scanf("%llu",&t);
		a=a+t%m;
	}
	for(i=1;i<=n;i++)
	{
		t=i*n%m;
		exgcd(t,a,x,y);
		printf("%llu ",x);
	}
	return 0;
}
void exgcd(LLU a,LLU b,LLU &x,LLU &y)
{
    if(!b)
    {
        x=1;y=0;
    }
    else
    {
        exgcd(b,a%b,y,x);
        y-=a/b*x;
    }
}