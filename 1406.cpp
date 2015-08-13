#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char a[2],b[2];
int m,cnt,root[101];
struct edge
{
	int x,y,l;
	friend bool operator<(edge a,edge b)
	{
		return a.l<b.l;
	}
}e[100];
int getroot(int x)
{
	if(x==root[x])
		return x;
	return root[x]=getroot(root[x]);
}
int main()
{
	while(scanf("%d",&n),n)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
			root[i]=i;
		for(int i=1;i<=n-1;i++)
		{
			scanf("%s",a);
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%s",b);
				int c;
				scanf("%d",&c);
				e[++cnt].x=*a-'A'+1;
				e[cnt].y=*b-'A'+1;
				e[cnt].l=c;
			}
		}
		sort(e+1,e+cnt+1);
		int sum=0;
		for(int i=1;i<=cnt;i++)
		{
			int x=e[i].x,y=e[i].y;
			x=getroot(x);
			y=getroot(y);
			if(x==y)
				continue;
			root[x]=y;
			sum+=e[i].l;
		}
		printf("%d\n",sum);
	}
	return 0;
}