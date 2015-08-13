#include<cstdio>
#include<cstring>
int n,k;
int dp[55][25][25][100];
char str[25][25];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
int in(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=n&&str[x][y]=='0';
}
int judge(int * x)
{
	for(int i=0;i<100;i++)
		if(x[i]!=0)
			return 1;
	return 0;
}
void add(int *x,int *y)
{
	int f=0;
	for(int i=0;i<100;i++)
	{
		x[i]=x[i]+y[i]+f;
		if(x[i]>=10)
		{
			x[i]-=10;
			f=1;
		}
		else 
			f=0;
	}
}
void DP()
{
	dp[0][1][1][0]=1;
	for(int w=1;w<=k;w++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(judge(dp[w-1][i][j]))
				{
					for(int d=0;d<4;d++)
					{
						int x=i+dx[d];
						int y=j+dy[d];
						if(!in(x,y))continue;
						add(dp[w][x][y],dp[w-1][i][j]);
					}
				}
	}
}
int main()
{
	while(2==scanf("%d%d",&n,&k))
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			scanf("%s",str[i]+1);
		if(str[1][1]=='1'||str[n][n]=='1')
		;
		else
		DP();
		int i;
		for(i=99;i>=0;i--)
			if(dp[k][n][n][i]!=0)
				break;
		if(i<0)
			printf("0\n");
		else
		{
			for(int j=i;j>=0;j--)
				printf("%d",dp[k][n][n][j]);
			puts("");
		}
	}
	return 0;
}
