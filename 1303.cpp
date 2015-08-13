#include<cstdio>
#include<cstring>
#include<algorithm>
#define pi 400
using namespace std;
int d[220],s[220];
int dp[2][810];
int path[21][810],cnt;
int n,m;
void DP()
{
	int p=1,q=0;
	memset(dp,-1,sizeof(dp));
	memset(path,0,sizeof(path));
	for(int i=1;i<=n;i++)
	{
		if(s[i]>dp[0][pi+d[i]])
		{
			dp[0][pi+d[i]]=s[i];
			path[1][pi+d[i]]=i;
		}
	}
	for(int i=1;i<m;i++,p^=1,q^=1)
	{
		memset(dp[p],-1,sizeof(dp[p]));
	for(int k=0;k<=800;k++)
	{
		if(path[i][k])
		{
			for(int j=1;j<=n;j++)
			{
				if(k+d[j]<0||k+d[j]>800)
					continue;
				if(dp[p][k+d[j]]<dp[q][k]+s[j])
				{
					int k1,k2;
					for(k1=i,k2=k;k1>0;k1--)
					{
						if(path[k1][k2]==j)break;
						k2-=d[path[k1][k2]];
					}
					if(k1==0)
					{
						dp[p][k+d[j]]=dp[q][k]+s[j];
						path[i+1][k+d[j]]=j;
					}
				}	
			}
		}
	}
	}
	p^=1;
	printf("Jury #%d\n",++cnt);
	int maxn=-1,in=-1;
	for(int i=0;i<=400;i++)
	if(dp[p][pi+i]!=-1||dp[p][pi-i]!=-1)
	{
		if(dp[p][pi+i]>dp[p][pi-i])
			maxn=dp[p][pi+i],in=i;
		else
			maxn=dp[p][pi-i],in=-i;
		break;
	}
	printf("Best jury has value %d for prosecution and value %d for defence:\n",(maxn+in)/2,(maxn-in)/2);
	int num[210];
	int tot=0;
	int ll=pi+in;
	while(m)
	{
		num[++tot]=path[m][ll];
		ll-=d[path[m][ll]];
		m--;
	}
	sort(num+1,num+1+tot);
	for(int i=1;i<=tot;i++)
		printf(" %d",num[i]);
	puts("\n");
	return;
}
int main()
{
	while(scanf("%d%d",&n,&m),n||m)
	{	
		for(int i=1;i<=n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			d[i]=a-b;
			s[i]=a+b;
		}
		DP();
	}
	return 0;
}
