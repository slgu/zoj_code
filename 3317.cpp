#include<cstdio>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
PII p[220];
int ans[110],is[110];
int n,m;
int main()
{
	while(scanf("%d%d",&n,&m),n||m)
	{	
		int x,y;
		memset(ans,0,sizeof(ans));
		memset(is,0,sizeof(is));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			p[2*i]=make_pair(2*x+1,i);
			p[2*i+1]=make_pair(2*y,i);
		}
		sort(p,p+2*n);
		for(int i=0;i<2*n;i++)
		{
			x=p[i].first,y=p[i].second;
			if(x&1)
			{
				for(int j=0;j<m;j++)
					if(is[j]==0)
					{
						ans[y]=j+1;
						is[j]=1;
						break;
					}
			}
			else
				if(ans[y])
				{
					is[ans[y]-1]=0;
				}
		}
		for(int i=0;i<n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
