#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
using namespace std;
int n,m;
bool g[maxn][maxn];
int l[maxn],vi[maxn];
struct node
{
	int id;
	int va;
	friend bool operator<(node a,node b)
	{
		return a.va<b.va;
	}
} p[maxn];
int gao()
{
		for(int i=1;i<=n;i++)
		{
			int x=p[i].id;
			int flag=0,y;
			for(int j=i+1;j<=n;j++)
			{
				int w=p[j].id;
				if(!g[x][w])continue;
				if(!flag)
				y=w,flag=1;
				else
				if(!g[y][w])
				return 1;
			}
		}
		return 0;
}
int main()
{
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(l,0,sizeof(l));
		memset(vi,0,sizeof(vi));
		memset(g,0,sizeof(g));
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			g[x][y]=g[y][x]=1;
		}
		for(int i=n;i>=1;i--)
		{
			int in,mx=-1,j;
			for(j=1;j<=n;j++)
				if(!vi[j]&&mx<l[j])
				mx=l[j],in=j;
			vi[in]=i;
			for(j=1;j<=n;j++)
				if(!vi[j]&&g[j][in])
				l[j]++;
		}
		for(int i=1;i<=n;i++)
		{
			p[i].id=i;
			p[i].va=vi[i];
		}
		sort(p+1,p+n+1);
		int ans=gao();
		if(!ans)
		printf("Perfect\n");
		else
		printf("Imperfect\n");
		puts("");
	}
	return 0;
}