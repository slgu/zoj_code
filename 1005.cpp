#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#define min(k1,k2) ((k1)<(k2))?(k1):(k2)
using namespace std;
int p[1010][1010];
int path[1010][1010];
string st[]={"fill A","fill B","pour B A","pour A B","empty A","empty B"};
int a,b,n;
struct node
{
	int x,y;
};
int px[1010][1010];
int py[1010][1010];
void print(int x,int y)
{
	if(x==0&&y==0)
		return;
	print(px[x][y],py[x][y]);
	cout<<st[path[x][y]]<<endl;
}		
void bfs()
{
	memset(p,0,sizeof(p));
	node s,t; 
	s.x=0,s.y=0;
	queue<node>q;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		int x=s.x,y=s.y;
		if(s.y==n)
		{
			print(x,y);
			return;
		}
		p[x][y]=1;
		if(!p[a][y])
		{
			path[a][y]=0;
			t.x=a,t.y=y;
			px[t.x][t.y]=x;
			py[t.x][t.y]=y;
			q.push(t);
		}
		if(!p[x][b])
		{
			path[x][b]=1;
			t.x=x,t.y=b;
			px[t.x][t.y]=x;
			py[t.x][t.y]=y;
			q.push(t);
		}
		int c=min(b-y,x);
		if(!p[x-c][y+c])
		{
			t.x=x-c,t.y=y+c;
			path[x-c][y+c]=3;
			px[t.x][t.y]=x;
			py[t.x][t.y]=y;
			q.push(t);
		}
		c=min(a-x,y);
		if(!p[x+c][y-c])
		{
			t.x=x+c,t.y=y-c;
			path[x+c][y-c]=2;
			px[t.x][t.y]=x;
			py[t.x][t.y]=y;
			q.push(t);
		}
		if(!p[0][y])
		{
			t.x=0,t.y=y;
			path[0][y]=4;		
			px[t.x][t.y]=x;
			py[t.x][t.y]=y;
			q.push(t);
		}
		if(!p[x][0])
		{
			t.x=x,t.y=0;
			path[x][0]=5;
			px[t.x][t.y]=x;
			py[t.x][t.y]=y;
			q.push(t);
		}	
	}
}
int main()
{
	while(scanf("%d%d%d",&a,&b,&n)!=EOF)
	{
		bfs();
		cout<<"success\n";
	}
	return 0;
}
