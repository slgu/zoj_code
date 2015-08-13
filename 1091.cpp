#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int vi[10][10];
int inside(int x,int y)
{
	return x>=0&&x<8&&y>=0&&y<8;
}
char a[3],b[3];
struct node
{
	int x,y,step;
};
int dic[][2]={2,1,2,-1,-2,-1,-2,1,1,2,-1,2,-1,-2,1,-2};
int main()
{
	while(scanf("%s%s",a,b)!=EOF)
	{
		memset(vi,0,sizeof(vi));
		int x=*a-'a',y=a[1]-'1';
		int m=*b-'a',n=b[1]-'1';
		node s,t;
		s.x=x,s.y=y;
		s.step=0;
		queue<node>q;
		q.push(s);
		int ans=0;
		while(!q.empty())
		{
			s=q.front();
			q.pop();
			int x=s.x,y=s.y;
			if(x==m&&y==n)
			{
				ans=s.step;
				break;
			}
			vi[x][y]=1;
			for(int i=0;i<8;i++)
			{
				int xx=x+dic[i][0];
				int yy=y+dic[i][1];
				if(!inside(xx,yy)||vi[xx][yy])
					continue;
				t.x=xx,t.y=yy,t.step=s.step+1;
				q.push(t);
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n",a,b,ans);
		
	}
	return 0;
}