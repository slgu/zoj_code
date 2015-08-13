#include<stdio.h>
char str[150][250];
int dp[150][250];
#include<string.h>
int min(int i,int j)
{
	return (i<j)?i:j;
}
int main()
{
	int n,i,j,max,cas=1;
	while(scanf("%d",&n),n)
	{
		max=-1;
		memset(dp,0,sizeof(dp));
		getchar();
		for(i=0;i<=n;i++)
			for(j=0;j<=2*n+1;j=j+2)
				str[i][j]=' ';
		for(i=1;i<=n;i++)
			gets(str[i]+1);
		for(i=1;i<=n;i++)
			for(j=i;j<=2*n-i;j++)
				if(str[i][j]=='-')
					if(str[i-1][j]=='-')
						dp[i][j]=min(dp[i-1][j-1],dp[i-1][j+1])+1;
					else
						dp[i][j]=1;
		for(i=n-1;i>=1;i--)
			for(j=i+1;j<=2*n-i;j+=2)
				if(str[i][j]=='-')
					if(str[i+1][j]=='-')
						dp[i][j]=min(dp[i+1][j-1],dp[i+1][j+1])+1;
					else
						dp[i][j]=1;

		for(i=1;i<=n;i++)
			for(j=i;j<=2*n-i;j++)
				if(max<dp[i][j])
					max=dp[i][j];
		printf("Triangle #%d\n",cas);
		printf("The largest triangle area is %d.\n\n",max*max);
		cas++;
	}
	return 0;
}