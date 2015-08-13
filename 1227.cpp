#include<cstdio>
#include<cstring>
int n;
const int INF=-99;
int vt[5][50];
int inside(int x1,int x2,int x3,int x4)
{
	return x1<=n+1&&x2<=n+1&&x3<=n+1&&x4<=n+1;
}
int min(int a,int b)
{
	return a>b?a:b;
}
int dic[4][4]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
int dp[50][50][50][50];
int dfs(int x1,int x2,int x3,int x4,long long ba,int count)
{
	if(count==5)
		return 0;
	if(dp[x1][x2][x3][x4]!=-1)
		return dp[x1][x2][x3][x4];
	int a=INF,y[5];	
	for(int i=0;i<4;i++)
	{
		y[1]=x1+dic[i][0];
		y[2]=x2+dic[i][1];
		y[3]=x3+dic[i][2];
		y[4]=x4+dic[i][3];
		if(!inside(y[1],y[2],y[3],y[4]))
				continue;
		int temp=y[i+1];
		int mem=vt[i+1][y[i+1]-1];
	//	printf("%d %d %d %d\n",y[1],y[2],y[3],y[4]);
		//getchar();
		if((long long)(1<<(mem-1))&ba)
		{
			ba-=(long long)(1<<(mem-1));
			count--;
			a=min(a,1+dfs(y[1],y[2],y[3],y[4],ba,count));
			count++;
			ba+=(long long)(1<<(mem-1));
		}
		else
		{
			ba+=(long long)(1<<(mem-1));
			count++;
			a=min(a,dfs(y[1],y[2],y[3],y[4],ba,count));
			ba-=(long long)(1<<(mem-1));
			count--;
		}
	}
	if(a==INF)
		a=0;
	return dp[x1][x2][x3][x4]=a;
}
int main()
{
	while(scanf("%d",&n),n)
	{
			memset(dp,-1,sizeof(dp));
			for(int i=1;i<=n;i++)
				scanf("%d%d%d%d",vt[1]+i,vt[2]+i,vt[3]+i,vt[4]+i);
			int ans=dfs(1,1,1,1,0,0);
			printf("%d\n",dp[1][1][1][1]);
	}
	return 0;
}