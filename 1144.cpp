#include<cstdio>
#include<cstring>
int w,h,t;
bool g[110][110][110];
int num[110],xx[110],yy[110];
int ok(int t,int x,int y,int f)
{
	if(x>1&&!g[t+f][x-1][y])return 0;
	if(x<w&&!g[t+f][x+1][y])return 0;
	if(y>1&&!g[t+f][x][y-1])return 0;
	if(y<h&&!g[t+f][x][y+1])return 0;
	if(!g[t+f][x][y])
	return 0;
	return 1;
}
int main()
{
	int pro=0;
	while(scanf("%d%d%d",&w,&h,&t),w||h||t)
	{
		int n,out=0;
		scanf("%d",&n);
		memset(g,0,sizeof(g));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
		{
			int t,a,b,c,d;
			scanf("%d%d%d%d%d",&t,&a,&b,&c,&d);
			for(int y=a;y<=c;y++)
			for(int z=b;z<=d;z++)
			g[t][y][z]=1;
		}
		printf("Robbery #%d:\n",++pro);
		for(int k=2;k<=t;k++)
		for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
		{
			if(!g[k][i][j]&&ok(k,i,j,-1))
				g[k][i][j]=1;
		}
		for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
		{
			if(!g[t][i][j])
			{
				num[t]++;
				xx[t]=i,yy[t]=j;
			}
		}
		if(num[t])
		out=1;
		for(int k=t-1;k>=1;k--)
		for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
			if(!g[k][i][j]&&ok(k,i,j,1))
				g[k][i][j]=1;
		for(int k=1;k<=t-1;k++)
		for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
		{
			if(!g[k][i][j])
			{
				num[k]++;
				xx[k]=i,yy[k]=j;
			}
		}
		if(!out)
		printf("The robber has escaped.\n");
		else
		{
			int flag=0;
			for(int i=1;i<=t;i++)
			{
				if(num[i]==1)
				{
					flag=1;
					printf("Time step %d: The robber has been at %d,%d.\n",i,xx[i],yy[i]);
				}
			}
			if(!flag)
			printf("Nothing known.\n");
		}
		puts("");
	}
	return 0;
}