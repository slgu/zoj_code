#include<cstdio>
#include<algorithm>
using namespace std;
int T,mp[1010][1010],a[1010],n,cnt,r[1010];
struct EDGE
{
	int x,y,l;
	friend bool operator<(EDGE A,EDGE B)
	{
		return A.l<B.l;
	}
}edge[600000];
int find(int x)
{
	if(r[x]==x)
		return x;
	else
		return r[x]=find(r[x]);
}
int krustral()
{
	sort(edge,edge+cnt);
	int ans=0,tot=0;
	for(int i=0;i<cnt;i++)
	{
		int x=edge[i].x,y=edge[i].y;
		x=find(x);
		y=find(y);
		if(x!=y)
		{
			r[x]=y;
			tot++;
			ans+=edge[i].l;
			if(tot==n-1)
				return ans;
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt=0;
		for(int i=0;i<n;i++)
			r[i]=i;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%d",&mp[i][j]);
				if(i!=j)
					mp[i][j]+=a[i]+a[j];
				if(i<j)
				{
					edge[cnt].x=i;
					edge[cnt].y=j;
					edge[cnt].l=mp[i][j];
					cnt++;
				}
			}
		printf("%d\n",krustral());
	}
	return 0;
}
