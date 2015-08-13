#include<cstdio>
#include<cstring>
int n;
int p[110][110];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int t;
			scanf("%d",&t);
			p[i][j]=p[i-1][j]+t;
		}
		int maxn=0;
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int sum=0;
			for(int k=1;k<=n;k++)
			{
				sum+=(p[j][k]-p[i-1][k]);
				if(sum<0)
				sum=0;
				if(sum>maxn)
				maxn=sum;
			}
		}
		printf("%d\n",maxn);
	}
	return 0;
}
