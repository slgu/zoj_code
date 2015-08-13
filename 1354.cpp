#include<cstdio>
#include<cstring>
int visit[10][10];
int status[10][10];
int n;
int inside(int x,int y)
{
	return x>=1&&x<=5&&y>=1&&y<=6;
}
int d[4][2]={1,0,0,1,-1,0,0,-1};
int dfs(int m)
{
	if(m>=31)
	{
		for(int i=1;i<=5;i++)
			for(int j=1;j<=6;j++)
				if(status[i][j])
					return 0;
		return 1;
	}
//	printf("%d\n",m);
	int x=(m-1)/6+1;
	int y=(m-1)%6+1;
	if(x==5&&inside(x,y-1)&&inside(x-1,y)&&status[x][y-1]^status[x-1][y])
		return 0;
	if(!inside(x-1,y)||status[x-1][y])
	{	
			visit[x][y]=1;
			status[x][y]^=1;
			int a,b;
			for(int i=0;i<4;i++)
			{
				a=x+d[i][0];
				b=y+d[i][1];
				if(!inside(a,b))
				continue;
				status[a][b]^=1;
			}
			if(dfs(m+1))
				return 1;
			visit[x][y]=0;
			status[x][y]^=1;
			for(int i=0;i<4;i++)
			{
				a=x+d[i][0];
				b=y+d[i][1];
				if(!inside(a,b))
				continue;
				status[a][b]^=1;
			}
	}
	if(!(inside(x-1,y)&&status[x-1][y]))
		return dfs(m+1);
	return 0;
}
int main()
{
	scanf("%d",&n);
	int count=0;
	while(n--)
	{
		for(int i=1;i<=5;i++)
			for(int j=1;j<=6;j++)
				scanf("%d",&status[i][j]);
		memset(visit,0,sizeof(visit));
		int ans=dfs(1);
		//printf("%d\n",ans);
		printf("PUZZLE #%d\n",++count);
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=6;j++)
			{
				if(j==1)
					printf("%d",visit[i][j]);
				else
					printf(" %d",visit[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}