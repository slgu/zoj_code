#include<cstdio>
#include<cstring>
const int inf=9999999;
int n,m;
int a[120],b[120],c[120],l[120],w[120];
int dp[120][120];
int min(int a,int b)
{
	if(a==-1)
		return b;
	return a<b?a:b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		scanf("%d%d%d%d%d",a+i,b+i,c+i,l+i,w+i);
		memset(dp,-1,sizeof(dp));
		dp[0][m]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=m;j++)
			{
				if(dp[i-1][j]!=-1)
				dp[i][j]=dp[i-1][j]+b[i];
				if(m>=j+l[i]&&dp[i-1][j+l[i]]!=-1)
					dp[i][j]=min(dp[i][j],dp[i-1][j+l[i]]+a[i]);
				if(j>=w[i]&&dp[i-1][j-w[i]]!=-1)
					dp[i][j]=min(dp[i][j],dp[i-1][j-w[i]]+c[i]);
				if(j==m)
					for(int z=j-w[i];z<=m;z++)
					{
						if(dp[i-1][z]!=-1)
						dp[i][j]=min(dp[i][j],dp[i-1][z]+c[i]);
					}
			}
		int ans=9999999;
		for(int i=0;i<=m;i++)
			if(dp[n][i]!=-1&&dp[n][i]<ans)
				ans=dp[n][i];
		printf("%d\n",ans);
	}
	return 0;
}
