#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c;
bool dp[301][301][301];
void init()
{
	for(int i=0;i<=300;i++)
		for(int j=0;j<=300;j++)
			for(int k=0;k<=300;k++)
			{
				if(dp[i][j][k]==0)
				{
					for(int w=i+1;w<=300;w++)
						dp[w][j][k]=1;
					for(int w=j+1;w<=300;w++)
						dp[i][w][k]=1;
					for(int w=k+1;w<=300;w++)
						dp[i][j][w]=1;
					for(int w=1;w+max(i,j)<=300;w++)
						dp[w+i][w+j][k]=1;
					for(int w=1;w+max(i,k)<=300;w++)
						dp[w+i][j][k+w]=1;
					for(int w=1;w+max(k,j)<=300;w++)
						dp[i][j+w][k+w]=1;
				}
			}
}
int main()
{
	init();
	while(3==scanf("%d%d%d",&a,&b,&c))
	{
		printf("%d\n",dp[a][b][c]);
	}
	return 0;
}
