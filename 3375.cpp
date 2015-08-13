#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[20],b[20],x[20],y[20];
int dp[1<<15];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d%d%d%d",a+i,b+i,x+i,y+i);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<(1<<n);i++)
		{
			int iv=0,tv=0;
			for(int j=0;j<n;j++)
			if(i&(1<<j))
			{
				tv+=a[j]*x[j];
				iv+=b[j]*y[j];
			}
			for(int j=0;j<n;j++)
			if(!(i&(1<<j)))
			{
				int z=i|(1<<j);
				int sum=max(iv*x[j]+y[j]*(tv+a[j]*x[j]),tv*y[j]+x[j]*(iv+b[j]*y[j]));
				dp[z]=max(dp[z],dp[i]+sum);
			}
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}
