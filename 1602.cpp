#include<cstdio>
#include<cstring>
#define max(a,b) ((a))<((b))?(a):(b)
const int inf=1000000000;
int n;
int p[110];
int dp[110][110];
int main()
{
	while(1==scanf("%d",&n))
	{
		for(int i=0;i<n;i++)	
			scanf("%d",p+i);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n-3;i++)
			dp[i][i+2]=p[i]*p[i+1]*p[i+2];
		for(int l=4;l<=n;l++)
			for(int i=0;i+l-1<n;i++)
			{
				int j=i+l-1;
				dp[i][j]=inf;
				for(int w=i+1;w<j;w++)
					dp[i][j]=max(dp[i][j],dp[i][w]+dp[w][j]+p[i]*p[j]*p[w]);
			}
		printf("%d\n",dp[0][n-1]);
	}
}
