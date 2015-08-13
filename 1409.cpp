#include<cstdio>
#include<cstring>
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int T,n,tmp;
typedef pair<int,int> PII;
const int inf=100000000;
vector< PII >vt[110];
int dp[11000],tp[11000];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		fill(dp,dp+11000,inf);
		for(int i=0;i<n;i++)
		vt[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			int m,p;
			for(int j=0;j<tmp;j++)
			{
				scanf("%d%d",&m,&p);
				vt[i].push_back(make_pair(m,p));
			}
		}
		PII pi;
		for(int i=0;i<vt[0].size();i++)
		{
			pi=vt[0][i];
			dp[pi.first]=min(dp[pi.first],pi.second);
		}
		for(int i=1;i<n;i++)
		{
			fill(tp,tp+11000,inf);
			for(int j=0;j<vt[i].size();j++)
			{
				pi=vt[i][j];
				int x=pi.first;
				int y=pi.second;
				for(int w=10000;w>=0;w--)
					if(dp[w]!=inf)
					{
						int c=min(x,w);
						tp[c]=min(tp[c],dp[w]+y);
					}
			}
			memcpy(dp,tp,sizeof(tp));
		}
		double ans=-1;
		for(int w=10000;w>=0;w--)
			if(dp[w]!=inf)
			ans=max(ans,w*1.0/dp[w]);
		printf("%.3f\n",ans);
	}
	return 0;
}
