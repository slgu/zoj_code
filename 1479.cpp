#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m,x1,x2,y1,y2;
int mp[25][25];
char st[2];
struct node
{
	int x,y;
	int sum;
	friend bool operator< (node a,node b)
	{		return a.sum > b.sum;}
};
int inside(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}
int dp[25][25];
int dic[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
int main()
{
	while(2==scanf("%d%d",&n,&m))
	{	
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				dp[i][j]=9999999;
		memset(mp,0,sizeof(mp));
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			int a,b;
			scanf("%d%d%s",&a,&b,st);
			if(*st=='B')
				mp[a][b]=-1;
			if(*st=='r')
				mp[a][b]=2;
			if(*st=='l')
				mp[a][b]=4;
			if(*st=='u')
				mp[a][b]=1;
			if(*st=='d')
				mp[a][b]=3;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]==1)
				{
					mp[i][j]=-1;
					for(int a=i-1;a>=1;a--)
					{
						if(mp[a][j]!=0&&mp[a][j]!=5)
							break;
						mp[a][j]=5;
					}
				}
				else
					if(mp[i][j]==2)
					{
						mp[i][j]=-1;
						for(int a=j+1;a<=m;a++)
						{
							if(mp[i][a]!=0&&mp[i][a]!=5)
								break;
							mp[i][a]=5;
						}
					}
					else
						if(mp[i][j]==3)
						{
							mp[i][j]==-1;
							for(int a=i+1;a<=n;a++)
							{
								if(mp[a][j]!=0&&mp[a][j]!=5)
									break;
								mp[a][j]=5;
							}
						}
					else
						if(mp[i][j]==4)
						{
							mp[i][j]=-1;
							for(int a=j-1;a>=1;a--)
							{
								if(mp[i][a]!=0&&mp[i][a]!=5)
									break;
								mp[i][a]=5;
							}
						}
			}
		int ans=-1;
		if(mp[x1][y1]!=0)
		{
			printf("-1\n");
			continue;
		}
		priority_queue<node>q;
		node s;
		s.x=x1,s.y=y1,s.sum=0;
		q.push(s);
		dp[x1][y1]=0;
		while(!q.empty())
		{
			s=q.top();
			q.pop();
			if(s.sum>dp[s.x][s.y])
				continue;
			int x,y;
			for(int i=0;i<8;i++)
			{
				x=s.x+dic[i][0];
				y=s.y+dic[i][1];
				if(!inside(x,y)||mp[x][y]==-1)
					continue;
				if(mp[x][y])
				{
					x+=dic[i][0];
					y+=dic[i][1];
					if(!inside(x,y)||mp[x][y]!=0)
						continue;
					if(dp[x][y]>s.sum+1)
					{
						dp[x][y]=s.sum+1;
						node u;
						u.x=x,u.y=y,u.sum=dp[x][y];
						q.push(u);
					}
				}
				else
					if(dp[x][y]>s.sum)
					{
						dp[x][y]=s.sum;
						node u;
						u.x=x,u.y=y,u.sum=dp[x][y];
						q.push(u);
					}
			}
		}
		if(dp[x2][y2]!=9999999)
		printf("%d\n",dp[x2][y2]);
		else
			printf("-1\n");
	}
	return 0;
}