#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int visit[60][60][60];
char map[60][60];
int bfs();
int total,n1,n2,n3;
typedef struct _node
{
	int number;
	int x;
	int y;
	int z;
} node;
int main()
{
	int k;
	while(cin>>total&&total)
	{
		memset(visit,0,sizeof(visit));
		cin>>n1>>n2>>n3;
		for(int i=0;i<total;i++)
			for(int j=0;j<total;j++)
				cin>>map[i][j];
		visit[n1-1][n2-1][n3-1]=1;
		k=bfs();
		if(k==-1)
			printf("impossible\n");
		else 
			printf("%d\n",k);
	}
	return 0;
}
int bfs()
{
	queue<node> pq;
	node p;
	p.x=n1-1;
	p.y=n2-1;
	p.z=n3-1;
	p.number=0;
	pq.push(p);
	int i;
	char c;
	node m,n;
	while(!pq.empty())
	{
		m=pq.front();
		if(m.x==m.y&&m.y==m.z)
			return m.number;
		pq.pop();
		c=map[m.y][m.z];
		for(i=0;i<total;i++)
		{
			if(!visit[i][m.y][m.z]&&map[i][m.x]==c)
			{
				visit[i][m.y][m.z]=1;
				n.number=m.number+1;
				n.x=i;
				n.y=m.y;
				n.z=m.z;
				pq.push(n);
			}
		}
		c=map[m.x][m.z];
		for(i=0;i<total;i++)
		{
			if(!visit[m.x][i][m.z]&&map[i][m.y]==c)
			{
				visit[i][m.y][m.z]=1;
				n.number=m.number+1;
				n.x=m.x;
				n.y=i;
				n.z=m.z;
				pq.push(n);
			}
		}
		c=map[m.y][m.x];
		for(i=0;i<total;i++)
		{
			if(!visit[m.x][m.y][i]&&map[i][m.z]==c)
			{
				visit[m.x][m.y][i]=1;
				n.number=m.number+1;
				n.x=m.x;
				n.y=m.y;
				n.z=i;
				pq.push(n);
			}
		}
	}
	return -1;
}