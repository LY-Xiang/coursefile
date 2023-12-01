#include <cstdio>
int main(void)
{
	int ans=0,ans_=0,p=0;
	for(int i=1;i<=50;i+=1)
	{
	ans+=(2*i-1)*2*i*(2*i+1);
	p=i*(i+1);
	ans_=p*(2*p-1);
	printf("%d %d\n",ans,ans_);
	}
	return 0;
}