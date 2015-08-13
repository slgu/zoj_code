//暴力BFS
#include<iostream>
#include<cstring>
using namespace std;
#include<queue>
char a[210][210];
int time1[210][210];
struct node
{
	int x;
	int y;
};
node g[4]={-1,0,1,0,0,1,0,-1};//省代码必备啊
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(a,0,sizeof(a));
		memset(time1,0,sizeof(time1));
		for(int i=1;i<=n;i++)
			cin>>a[i]+1;
		int x1,y1;
		int x2,y2;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='r')
				{
					x1=i;
					y1=j;
				}
				if(a[i][j]=='a')
				{
					x2=i;
					y2=j;
				}
			}
		queue<node> q;
		node k;
		k.x=x1;k.y=y1;
		time1[x1][y1]=1;
		q.push(k);
		while(!q.empty())
		{
			node c=q.front();
			q.pop();
			int i=c.x;
			int j=c.y;
			for(int m=0;m<4;m++)
			{
				int t1=i+g[m].x;
				int t2=j+g[m].y;
				if(a[t1][t2]=='#'||a[t1][t2]=='\0')
					continue;
					if(a[t1][t2]=='x')
					{
						if(time1[t1][t2]==0||time1[i][j]+2<time1[t1][t2])
						{
							time1[t1][t2]=time1[i][j]+2;
							node k;
							k.x=t1;k.y=t2;
							q.push(k);
						}
					}
					else
						if(time1[t1][t2]==0||time1[i][j]+1<time1[t1][t2])
						{
							time1[t1][t2]=time1[i][j]+1;
							node k;
							k.x=t1;k.y=t2;
							q.push(k);
						}

			}
		}
		if(time1[x2][y2])
			cout<<time1[x2][y2]-1<<endl;
		else
			cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
	}
	return 0;
}
