#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
int p[30];
int ans[30];
int cnt;
int dp[1<<20];
const int mod=(1<<20)-1;
int DP(int x)
{
	if(dp[x]!=-1)return dp[x];
	int f=0;
	int y;
	for(int j=2;j<=20;j++)
	{
		y=x;
		if(x&(1<<(j-1)))
		{
			for(int c=1;j*c<=20;c++)
			{
				y&=(mod-(1<<(j*c-1)));
				for(int w=2;w+c*j<=20;w++)
					if(!(x&(1<<(w-1))))
					y&=(mod-(1<<(w+c*j-1)));
			}
			if(!DP(y))
			{
				f=1;
			}
		}
	}
	return dp[x]=f;
}
int main()
{
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	int pro=0;
	while(T--)
	{
		printf("Scenario #%d:\n",++pro);
		scanf("%d",&n);
		cnt=0;
		int q=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",p+i);
			q|=(1<<(p[i]-1));
		}
		DP(q);
		for(int j=2;j<=20;j++)
		{
			int y=q;
			if(q&(1<<(j-1)))
			{
				for(int c=1;j*c<=20;c++)
				{
					y&=(mod-(1<<(j*c-1)));
					for(int w=2;w+c*j<=20;w++)
					if(!(q&(1<<(w-1))))
					y&=(mod-(1<<(w+c*j-1)));
				}
				if(!DP(y))
					ans[cnt++]=j;
			}
		}
		if(cnt==0)
			printf("There is no winning move.\n");
		else
		{
			sort(ans,ans+cnt);
			printf("The winning moves are:");
			for(int i=0;i<cnt;i++)
				printf(" %d",ans[i]);
			puts(".");
		}
		puts("");
	}
	return 0;
}
