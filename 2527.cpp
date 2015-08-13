#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;
int n,a[1010],dp[1010][1010],ans;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);		
		sort(a,a+n);
		memset(dp,0,sizeof(dp));
		ans=2;
		dp[0][1]=2;
		for(int i=2;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				dp[j][i]=2;
				for(int k=0;k<j;k++)
				{
					if(a[j]*2==a[i]+a[k])
						dp[j][i]=max(dp[j][i],dp[k][j]+1);
					ans=max(ans,dp[j][i]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
