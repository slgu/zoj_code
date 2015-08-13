#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m,k,p;
int acm[70][70][70];
struct node
{
	int x,y,z;
};
int dx[]={1,0,0,-1,0,0};
int dy[]={0,1,0,0,-1,0};
int dz[]={0,0,1,0,0,-1};
int main()
{
	while(scanf("%d%d%d%d",&n,&m,&k,&p),n||m||k||p)
	{
		memset(acm,0,sizeof(acm));
		for(int i=0;i<p;i++)
		{
			int w;
			scanf("%d",&w);
			int c=w/(m*n);
			int a=w%n;
			int b=(w%(m*n))/n;
			acm[a+1][b+1][c+1]=1;
		}
		queue<node>q;
		acm[0][0][0]=-1;
		node  s;
		s.x=s.y=s.z=0;
		q.push(s);
		int ans=0;
		while(!q.empty())
		{
			s=q.front();
			q.pop();
			int x=s.x,y=s.y,z=s.z;
			for(int i=0;i<6;i++)
			{
				int tx=x+dx[i],ty=y+dy[i],tz=z+dz[i];
				if(tx>=0&&tx<=n+1&&ty>=0&&ty<=m+1&&tz>=0&&tz<=k+1)
				{
					if(!acm[tx][ty][tz])
					{
						acm[tx][ty][tz]=-1;
						node t;
						t.x=tx,t.y=ty,t.z=tz;
						q.push(t);
					}
					else if(acm[tx][ty][tz]==1)
						ans++;
				}
			}
		}
		printf("The number of faces needing shielding is %d.\n",ans);
	}
	return 0;
}
