#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int inf=1000000001;
struct node
{
	int x,l;	
	node(int a,int b):x(a),l(b){}
};
vector<node>vt[2][1000010];
int T,n,m,a,b,l,dis[1000010],in[1000010];
int spfa(int f)
{
	memset(in,0,sizeof(in));
	fill(dis,dis+n+1,inf);
	dis[1]=0;
	queue<int>q;
	in[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		in[s]=0;
		for(int i=0;i<vt[f][s].size();i++)
		{
			int y=vt[f][s][i].x,l=vt[f][s][i].l;
			if(dis[y]>dis[s]+l)
			{
				dis[y]=dis[s]+l;
				if(!in[y])
				{
					in[y]=1;
					q.push(y);
				}
			}
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		ans+=dis[i];
	}
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			vt[0][i].clear();
			vt[1][i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&l);
			vt[0][a].push_back(node(b,l));
			vt[1][b].push_back(node(a,l));
		}
		printf("%d\n",spfa(0)+spfa(1));	
	}
	return 0;
}
