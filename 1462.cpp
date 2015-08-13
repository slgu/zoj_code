#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
vector<int>s[2][150];
int mp[150][150],p[150][150],vi[150],dp[150][150];
int path[150],c[150];
int t,n,cnt;
struct node
{
	int x;
	int va;
};
int dfs(int i,int va)
{
	vi[i]=1;
	c[i]=va;
	s[va][cnt].push_back(i);
	for(int j=1;j<=n;j++)
		if(i!=j&&p[i][j])
		{
			if(vi[j])
			{
				if((c[i]%2)==(c[j]%2))
					return 1;
			}
			else
			if(dfs(j,va^1))
				return 1;
		}
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<110;j++)
				s[i][j].clear();
		memset(mp,0,sizeof(mp));
		memset(p,0,sizeof(p));
		memset(vi,0,sizeof(vi));
		memset(path,0,sizeof(path));
		for(int i=1;i<=n;i++)
		{
			int a;
			while(scanf("%d",&a)==1&&a)
				mp[i][a]=1;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(mp[i][j]==0||mp[j][i]==0)
					p[i][j]=p[j][i]=1;
			}
		int ff=0;
		for(int i=1;i<=n;i++)
		{
			if(vi[i])
				continue;
			cnt++;
			if(dfs(i,1))
			{
				ff=1;
				break;
			}
		}
		if(ff)
		{
			printf("No solution\n");
			if(t)
				puts("");
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=cnt;i++)
		{
			for(int j=n/2;j>=0;j--)
			{
				if(dp[i-1][j])
				{
					dp[i][j+s[0][i].size()]=1;
					dp[i][j+s[1][i].size()]=2;
				}
			}
		}
		int sum;
		for(sum=n/2;sum>=0;sum--)
		{
			if(dp[cnt][sum])
				break;
		}
		int index=0;
		for(int i=cnt;i>=1;i--)
		{
			if(dp[i][sum]==1)
			{
				sum-=s[0][i].size();
				for(int j=0;j<s[0][i].size();j++)
					path[++index]=s[0][i][j];
			}
			else
			{
				sum-=s[1][i].size();
				for(int j=0;j<s[1][i].size();j++)
					path[++index]=s[1][i][j];
			}
		}
		memset(vi,0,sizeof(vi));
		printf("%d",index);
		for(int i=1;i<=index;i++)
		{
			printf(" %d",path[i]);
			vi[path[i]]=1;
		}
		puts("");
		printf("%d",n-index);
		for(int i=1;i<=n;i++)
		{
			if(!vi[i])
				printf(" %d",i);
		}
		puts("");
		if(t)puts("");
	}
	return 0;
}
