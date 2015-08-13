#include<cstdio>
#include<cstring>
int n,k,t;
int num[5010];
int dp[5100][1100];
int min(int a,int b)
{
	return a<b?a:b;
}
int mul(int a)
{
	return a*a;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&k,&n);
		k+=8;
		for(int i=1;i<=n;i++)
			scanf("%d",num+i);
		dp[n-2][1]=mul(num[n-2]-num[n-1]);	
		for(int i=n-3;i>=1;i--)
		for(int j=1;j<=k;j++)
		{
			if(n-i+1<3*j)
				break;
			else
				if(n-i+1==3*j)
				dp[i][j]=dp[i+2][j-1]+mul(num[i]-num[i+1]);
			else
				dp[i][j]=min(dp[i+1][j],dp[i+2][j-1]+mul(num[i]-num[i+1]));
		}
		printf("%d\n",dp[1][k]);
	}
	return 0;
}