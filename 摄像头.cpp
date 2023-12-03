#include <cstdio>
unsigned short n,i,j,x,y,**m,*xy[500+1];
void s(unsigned short);
int main(void)
{
	scanf("%hu",&n);
	m=new unsigned short*[n];
	for(i=0;i<n;i++)
	{
		scanf("%hu",&x);
		m[i]=xy[x];
		scanf("%hu",m[i]);
		xy[x]=new unsigned short[*m[i]+1];
		for(j=1;j<=*m[i];j++)
			scanf("%hu",m[i]+j);
	}
	return 0;
}