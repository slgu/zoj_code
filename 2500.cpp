#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>vt[110],rvt[110];
int vi[110],d[110],dp[110],rdp[110];
int  T,n,m,a,b,cnt;
int top()
{
	memset(vi,0,sizeof(vi));
	int in;
	for(int i=1;i<=n;i++)
	{
		in=-1;
		for(int j=1;j<=n;j++)
			if(d[j]==0&&!vi[j])
			{
				in=j;
				vi[j]=1;
				break;
			}
		if(in==-1)return 1;
		for(int i=0;i<vt[in].size();i++)
		{
			int y=vt[in][i];
			if(!vi[y])d[y]--;
		}
	}
	return 0;
}
void dfs(int x)
{
	cnt++;
	vi[x]=1;
	for(int i=0;i<vt[x].size();i++)
	{
		int y=vt[x][i];
		if(vi[y])continue;
		dfs(y);
	}
}
void rdfs(int x)
{
	cnt++;
	vi[x]=1;
	for(int i=0;i<rvt[x].size();i++)
	{
		int y=rvt[x][i];
		if(vi[y])continue;
		rdfs(y);
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		memset(vi,0,sizeof(vi));
		for(int i=1;i<=n;i++)
		{
			vt[i].clear();
			rvt[i].clear();
		}
		memset(d,0,sizeof(d));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			vt[a].push_back(b);
			rvt[b].push_back(a);
			d[b]++;
		}
		if(top())
		{
			printf("%d\n",n);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			memset(vi,0,sizeof(vi));
			dfs(i);
			dp[i]=cnt-1;
		}
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			memset(vi,0,sizeof(vi));
			rdfs(i);
			rdp[i]=cnt-1;
		}
		int ans=0,c=(n+1)/2;
		for(int i=1;i<=n;i++)
		{
			if(rdp[i]>c-1||dp[i]>n-c)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
