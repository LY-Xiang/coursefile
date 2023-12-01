#define _METHOD 1
#if _METHOD == 1
#include<cstdio>
using namespace std;
int main()
{
	int n,d,i,v[100000]={0},a[100000+1]={100001},ans=0,oil=0,L;
	scanf("%d%d",&n,&d);
	for(i=1;i<n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		if(a[i]<a[0])
			a[0]=a[i];
		if(v[i]>oil)
		{
			L=(v[i]-oil+d-1)/d;
			ans+=L*a[0];
			oil+=L*d;
		}
		oil-=v[i];
	}
	printf("%d",ans);
	return 0;
}
#endif
#undef _METHOD[0];
			oil+=L*d;
		}
		oil-=v[i];
		v[0]-=v[i];
	}
	if(v[0]>oil)
		ans+=(v[0]-oil+d-1)/d*a[i];
	printf("%d",ans);
	return 0;
}
#endif
#undef _METHOD