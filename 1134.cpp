#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n;
vector<int>vt[1600];
int deep[1600];
int dp[1600];
int minn(int a,int b)
{
	return a<b?a:b;
}
void dfs(int x,int fa)
{
	if(vt[x].size()==1&&x!=1)
	{
		dp[x]=0;
		return;
	}
	for(int i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==fa)
			continue;
		dfs(vt[x][i],x);
	}
	int a=1;
	for(int i=0;i<vt[x].size();i++)
		a+=dp[vt[x][i]];
	int b=(x==1)?vt[x].size():vt[x].size()-1;
	for(int i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==fa)
			continue;
		int d=vt[x][i];
		for(int j=0;j<vt[d].size();j++)
			if(vt[d][j]!=x)
				b+=dp[vt[d][j]];
	}
	a=minn(a,b);
	dp[x]=a;
}
int main()
{
	while(scanf("%d",&n)==1)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			vt[i].clear();
		for(int i=1;i<=n;i++)
		{
			int a,b,d;char c;
			scanf("%d",&a);
			a++;
			while((c=getchar())!='(')
				;
			scanf("%d",&b);
			c=getchar();
			for(int i=1;i<=b;i++)
			{
				scanf("%d",&d);
				d++;
				vt[a].push_back(d);
				vt[d].push_back(a);
			}
		}
		dfs(1,0);
		printf("%d\n",dp[1]);
	}
	return 0;
}
