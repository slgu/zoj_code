#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,a,b;
int mp[101][101],g[101][101];
int v[101];
int dis[101],p[101],inq[101],vi[101];
const int inf=99999999;
void spfa(int a,int b)
{
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	dis[a]=0;
	memset(inq,0,sizeof(inq));
	queue<int>q;
	q.push(a);
	inq[a]=1;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		inq[s]=0;
		for(int i=1;i<=n;i++)
		{
			if(i==s)
				continue;
			if(mp[s][i]!=-1&&dis[s]+mp[s][i]+v[i]<dis[i])
			{
				dis[i]=dis[s]+mp[s][i]+v[i];
				if(!inq[i])
				{
					inq[i]=1;
					q.push(i);
				}
			}
		}
	}
}
void print(int x)
{
	if(x==a)
	{
		printf("%d",x);
			return;
	}
	print(p[x]);
	printf("-->%d",x);
}
int  dfs(int x)
{
	vi[x]=1;
	if(x==b)
	{
		return 1;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==x||vi[i])
		continue;
		if(g[x][i]&&dfs(i))
		{
			p[i]=x;
			return 1;
	
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		for(int i=1;i<=n;i++)
			scanf("%d",v+i);
		while(1)
		{
			scanf("%d%d",&a,&b);
			memset(g,0,sizeof(g));
			if(a==-1&&b==-1)
				break;
			printf("From %d to %d :\n",a,b);
			printf("Path: "); 
			if(a==b)
			{
				printf("%d\n",a);
				printf("Total cost : %d\n\n",0);
				continue;
			}
			spfa(a,b);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(i==j)continue;
					if(mp[i][j]==-1)
						continue;
					if(dis[i]+mp[i][j]+v[j]==dis[j])
						g[i][j]=1;
				}
			memset(vi,0,sizeof(vi));
			p[a]=0;
			vi[a]=1;
			dfs(a);
			print(b);
			puts("");
			printf("Total cost : %d\n\n",dis[b]-v[b]);
		}
	
	}
	return 0;
}