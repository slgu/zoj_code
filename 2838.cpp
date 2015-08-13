#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int n,m,cnt,tot;
vector<int>vt[51000];
int rmq[110000],p[110000],fi[51000];
int num[110000],vi[51000],r[110000],f[110000][20];
void dfs(int x,int fa)
{
	vi[x]=1;
	p[x]=fa;
	num[x]=cnt++;
	r[num[x]]=x;
	fi[x]=tot;
	rmq[tot++]=num[x];
	int ff=0;
	for(int i=0;i<vt[x].size();i++)
	{
		int y=vt[x][i];
		if(vi[y])continue;
		ff++;
		dfs(y,x);
		rmq[tot++]=num[x];
	}
}
int get(int x)
{
	int c=-1;
	while(x)
	{
			c++;
			x>>=1;
	}
	return c;
}
void RMQ()
{
	for(int i=0;i<2*n;i++)	
			f[i][0]=rmq[i];
	int k=get(2*n+1);
	for(int j=1;j<=k;j++)
		for(int i=0;i<=2*n;i++)
		{
			if(i+(1<<j)-1>2*n)break;
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
}
int qu(int x,int y)
{
	if(x>y)
	swap(x,y);
	int k=get(y-x+1);
	return min(f[x][k],f[y-(1<<k)+1][k]);
}
int main()
{
	int ft=0,pro=0;;
	while(scanf("%d",&n)!=EOF)
	{
		cnt=tot=0;
		if(ft)printf("\n");
		else
				ft=1;
		printf("Case %d:\n",++pro);
		memset(vi,0,sizeof(vi));
		for(int i=0;i<n;i++)
				vt[i].clear();
		int x,y;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&x,&y);
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		dfs(0,-1);
	/*	printf("%d\n",cnt);
		for(int i=0;i<n;i++)
			printf("%d %d\n",i,num[i]);*/
		RMQ();
		//printf("\n\n");
	//	for(int i=0;i<2*n-1;i++)
	//		printf("%d\n",rmq[i]);
	//	printf("\n\n");
		scanf("%d",&m);
		int a,b,c,z;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			x=fi[a];
			y=fi[b];
			z=fi[c];
			int t,tt;
			t=qu(x,y);
			if(r[t]==c)
					puts("Yes");
			else
			{
				t=qu(x,z);
				tt=qu(y,z);
				int f=(r[t]==c)+(r[tt]==c);
				if(f==1)
					puts("Yes");
				else
					puts("No");
			}
		}
	}
}