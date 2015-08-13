#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int dp[1001];
int ndp[1001];
int sum[1001];
int t[1001];
int f[1001];
vector<int> vt[1001];
int n;
int dfs2(int x,int fa)
{
	if(vt[x].size()==0)
		return t[x];
	int a=t[x];
	for(int i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==fa)
			continue;
		a+=dfs2(vt[x][i],x);
	}
	return a;
}
int dfs(int  x,int fa)
{
	if(vt[x].size()==0)
	{
		sum[x]=dp[x]=t[x];
		ndp[x]=0;
		return t[x];
	}
	int temp=t[x],dsum=0;
	for(int i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==fa)
			continue;
		temp+=dfs(vt[x][i],x);
		dsum+=ndp[vt[x][i]];
	}
	if(vt[x].size()==1)
	{
		ndp[x]=sum[vt[x][0]];
	}
	else
	{
		int max=-1;
		for(int i=0;i<vt[x].size();i++)
		{
			if(vt[x][i]==fa)
				continue;
			if(max<sum[vt[x][i]]+dsum-ndp[vt[x][i]])
				max=sum[vt[x][i]]+dsum-ndp[vt[x][i]];
		}
		ndp[x]=max;
	}
	if(vt[x].size()==1)
	{
		dp[x]=sum[vt[x][0]]+t[x];
	}
	else
	{
		int max=-1;
		for(int i=0;i<vt[x].size();i++)
			for(int j=0;j<vt[x].size();j++)
			{
				if(i==j)
					continue;
				if(vt[x][i]==fa||vt[x][j]==fa)
					continue;
				else
					if(max<sum[vt[x][i]]+dp[vt[x][j]]+dsum-ndp[vt[x][i]]-ndp[vt[x][j]])
						max=sum[vt[x][i]]+dp[vt[x][j]]+dsum-ndp[vt[x][i]]-ndp[vt[x][j]];
			}
		dp[x]=max+t[x];
	}
	return sum[x]=temp;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		memset(dp,0,sizeof(dp));
		memset(ndp,0,sizeof(ndp));
		memset(sum,0,sizeof(sum));
		memset(t,0,sizeof(t));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			vt[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&t[i]);
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			f[i]=a;
			if(a==-1)
				continue;
			else
			{
				a++;
				vt[a].push_back(i);
			}
		}
		dfs(n,-1);
		int ans=0;
		for(int i=1;i<n;i++)
			if(f[i]==-1)
			ans+=dfs2(i,-1);
		printf("%d\n",dp[n]+ans);
	}
	return 0;
}