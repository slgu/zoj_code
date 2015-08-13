#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,w[3],s[3],d[3],cw[110],cs[110],n1,n2,n3,d4;
int dp[2][510][510];
int main()
{
	int rp=0;
	while(scanf("%d",&n),n)
	{
		if(rp)puts("");
		for(int i=0;i<3;i++)
			scanf("%d%d%d",w+i,s+i,d+i); 	
		scanf("%d%d%d%d",&n1,&n2,&n3,&d4);
		for(int i=1;i<=n;i++)
			scanf("%d%d",cw+i,cs+i);
		memset(dp,-1,sizeof(dp));
		int p=0,q=1;
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++)
		{
			memset(dp[q],-1,sizeof(dp[q]));
			for(int j=0;;j++)
			{
				if(j*w[0]>cw[i]||j*s[0]>cs[i])
					break;
				for(int k=0;;k++)
				{
					if(j*w[0]+k*w[1]>cw[i]||j*s[0]+k*s[1]>cs[i])
						break;
					int t=min((cw[i]-j*w[0]-k*w[1])/w[2],(cs[i]-j*s[0]-k*s[1])/s[2]);
					for(int z1=0;z1<=500;z1++)
						for(int z2=0;z1+z2<=500;z2++)
						{
							if(dp[p][z1][z2]==-1)continue;
							dp[q][z1+j][z2+k]=max(dp[q][z1+j][z2+k],dp[p][z1][z2]+t);
						}
				}
			}
			p=(p+1)%2;
			q=(q+1)%2;
		}
		p=n&1;
		int ans=-1;
		for(int i=0;i<=500;i++)
			for(int j=0;j<=500;j++)
			{
				if(dp[p][i][j]==-1)continue;
				int k=dp[p][i][j];
				int defense=i*d[0]+j*d[1]+k*d[2];
				defense+=max(0,min(i/n1,min(j/n2,k/n3))*(d4-n1*d[0]-n2*d[1]-n3*d[2]));
				if(ans<defense)ans=defense;
			}
		printf("Case %d: %d\n",++rp,ans);
	}
	return 0;
}
