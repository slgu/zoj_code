#include<cstdio>
#include<cstring>
int n,m;
long long dp[2][25000];
int cnt[100000][2];
int mul[20];
int in;
void dfs(int i,int a,int b)
{
	if(i>m+1)
		return;
	if(i==m+1)
	{
		cnt[++in][0]=a,cnt[in][1]=b;
		return;
	}
	dfs(i+3,a*27+13,b*27+13);
	dfs(i+1,a*3+1,b*3+2);
	dfs(i+1,a*3+2,b*3);
	dfs(i+1,a*3,b*3+1);
}
int main()
{
	mul[0]=1;
	for(int i=1;i<=9;i++)
		mul[i]=3*mul[i-1];
	while(scanf("%d%d",&m,&n),n||m)
	{
		in=0;
		if(m>n)
		{
			int temp=m;
			m=n,n=temp;
		}
		dfs(1,0,0);
		memset(dp,0,sizeof(dp));
		int s=0;
		for(int i=0;i<m;i++)
			s+=mul[i];
		dp[1][s]=1;
		int p,q,i;
		for(i=2,p=1,q=0;i<=n+1;p^=1,q^=1,i++)
		{
			memset(dp[q],0,sizeof(dp[q]));
			for(int j=1;j<=in;j++)
			{
				int a=cnt[j][0],b=cnt[j][1];
				dp[q][b]+=dp[p][a];
			}
		}
		printf("%lld\n",dp[p][s]);
	}
	return 0;
}
