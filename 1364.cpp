#include<cstdio>
#include<cstring>
int n,m,k;
int g[110][110];
int match[110];
int v[110];
int dfs(int x)
{
	for(int i=0;i<m;i++)
	{
		if(g[x][i]&&!v[i])
		{
			v[i]=1;
			if(match[i]==-1||dfs(match[i]))
			{
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int gao()
{
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<n;i++)
	{
		memset(v,0,sizeof(v));
		ans+=dfs(i);
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n),n)
	{	
		memset(g,0,sizeof(g));
		scanf("%d%d",&m,&k);
		for(int i=1;i<=k;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(b==0||c==0)
			continue;
			g[b][c]=1;
		}
		printf("%d\n",gao());
	}
	return 0;
}
