#define _METHOD 1
#if _METHOD == 1
#include<cstdio>
using namespace std;
int main()
{
	int n,n_,ans=0,r;
	scanf("%d",&n);
	for(r=1,n_;n_;r++,n_=n_*2/3)
		if(!ans&&n_%3==1)ans=r;
	printf("%d %d",r-1,ans);
	return 0;
}
#endif
#undef _METHOD			{ 
				c++;
				if(c%3==1)
				{
					n_--;
					a[i]=true;
				}
				if(i==n)
					ans=r;
			}
	}
	printf("%d %d",r-1,ans);
	return 0;
}
#endif
#undef _METHOD