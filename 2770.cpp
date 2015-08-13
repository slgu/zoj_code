#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,c[1010],dp[1010],in[1010],cnt[1010];
const int inf=99999999;
struct node
{
	int y,l;
};
vector<node>vt[1010];
void gao()
{
	for(int i=0;i<=1001;i++)
		dp[i]=inf;
	memset(in,0,sizeof(in));
	memset(cnt,0,sizeof(cnt));
	dp[n]=0;
	queue<int>q;
	q.push(n);
	in[n]=1;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		cnt[s]++;
		if(cnt[s]>n)
		{
			printf("Bad Estimations\n");
			return;
		}
		in[s]=0;
		for(int i=0;i<vt[s].size();i++)
		{
			node t=vt[s][i];
			if(dp[t.y]>dp[s]+t.l)
			{
				dp[t.y]=dp[s]+t.l;
				if(!in[t.y])
				{
					in[t.y]=1;
					q.push(t.y);
				}
			}
		}
	}
	printf("%d\n",-dp[0]);
}
int main()
{
	while(2==scanf("%d%d",&n,&m))
	{
        for(int i=0;i<=n;i++)
        vt[i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",c+i);
			node s;
			s.y=i,s.l=c[i];
			vt[i-1].push_back(s);
			s.y=i-1;
			s.l=0;
			vt[i].push_back(s);
		}
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			node s;
			s.y=a-1,s.l=-c;
			vt[b].push_back(s);
		}
		gao();
	}
	return 0;
}