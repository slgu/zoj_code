#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int dp[5][9][9];
int mp[10][10];
int a,b,c,d;
int dic[][2]={1,0,0,1,0,-1,-1,0};
int in(int a,int b)
{
	return a>=1&&a<=8&&b>=1&&b<=8;
}
struct node
{
	int x,y,st,cost;
	friend bool operator<(node a,node b)
	{
		return a.cost>b.cost;
	}
};
int main()
{
	while(scanf("%d%d%d%d",&a,&b,&c,&d),a||b||c||d)
	{
		for(int i=1;i<=8;i++)
			for(int j=1;j<=8;j++)
				scanf("%d",&mp[i][j]);
		memset(dp,-1,sizeof(dp));
		dp[1][a][b]=0;
		priority_queue<node>q;
		node s,t;
		s.x=a,s.y=b,s.st=1,s.cost=0;
		q.push(s);
		int ans=-1;
		while(!q.empty())
		{
			s=q.top();
			q.pop();
			int x=s.x,y=s.y;
			if(x==c&&y==d)
			{
				ans=s.cost;
				break;
			}
			for(int i=0;i<4;i++)
			{
				int xx=x+dic[i][0];
				int yy=y+dic[i][1];
				if(!in(xx,yy))
					continue;
				int cs=s.st*mp[xx][yy];
				int st=cs%4+1;
				cs+=s.cost;
				if(dp[st][xx][yy]==-1||dp[st][xx][yy]>cs)
				{
					dp[st][xx][yy]=cs;
					t.x=xx;
					t.y=yy;
					t.st=st;
					t.cost=cs;
					q.push(t);
				}
			}
		}
		printf("%d\n",ans);
	}			
	return 0;
}
