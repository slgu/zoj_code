#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=100;
int dp[110][220],T,n,ta[110],tb[110];
void checkmin(int &a,int b)
{
	if(b==-1)return;
	if(a==-1)a=b;
	else
		a=(a<b)?a:b;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++)
			scanf("%d%d",&ta[i],&tb[i]);
		dp[0][100]=0;
		for(int i=1;i<=n;i++)
			for(int ct=-99;ct<=99;ct++)
			{
				if(dp[i-1][ct+inf]!=-1)
				{
					if(ct<0)
					{
						checkmin(dp[i][ct+inf+ta[i]],dp[i-1][ct+inf]+max(0,ta[i]+ct));
						checkmin(dp[i][inf-tb[i]],dp[i-1][ct+inf]+tb[i]);
					}
					else
					{
						checkmin(dp[i][ta[i]+inf],dp[i-1][ct+inf]+ta[i]);
						checkmin(dp[i][ct+inf-tb[i]],dp[i-1][ct+inf]+max(0,tb[i]-ct));
					}
				}
			}
		int ans=-1;
		for(int i=0;i<200;i++)
			checkmin(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}
