#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
	int x,y,step,hp;
};
int dp[10][10][10],n,m;
int g[10][10];
int dic[][2]={1,0,0,1,-1,0,0,-1};
int bfs()
{
	queue<node>q;
	int sx,sy,dx,dy;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]==2)
				sx=i,sy=j;
			if(g[i][j]==3)
				dx=i,dy=j;
		}
	node s,t;
	s.x=sx,s.y=sy,s.hp=6;s.step=0;
	q.push(s);
	memset(dp,0,sizeof(dp));
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		if(s.x==dx&&s.y==dy)
		{
			return s.step;
		}
		if(s.hp==1)
			continue;
		for(int i=0;i<4;i++)
		{
			int x=s.x+dic[i][0];
			int y=s.y+dic[i][1];
			if(x<1||x>n||y<1||y>m||g[x][y]==0)
				continue;
			t.x=x,t.y=y;
			t.step=s.step+1;
			t.hp=s.hp-1;
			if(g[x][y]==4)
				t.hp=6;
			if(dp[t.x][t.y][t.hp])
				continue;
			dp[t.x][t.y][t.hp]=1;
			q.push(t);
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d%d",&m,&n),m||n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&g[i][j]);
		printf("%d\n",bfs());	
	}
}
