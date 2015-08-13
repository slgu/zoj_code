#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 1000
#define MAXM 500000
using namespace std;
int n;
int v[MAXN],root[MAXN],question[MAXN][MAXN],vi[MAXN],cnt[MAXN],f[MAXN];
vector<int>vt[MAXN];
int find(int x)
{
	return (x==root[x])?x:(root[x]=find(root[x]));
}
void un(int x,int y)
{
	x=find(x);
	y=find(y);
	root[x]=y;
}
void dfs(int x,int fa)
{
	root[x]=x;
	for(int i=0;i<vt[x].size();i++)
	{
		int y=vt[x][i];
		dfs(y,x);
		un(y,x);//访问完一个节点再把它和父亲连起来
	}
	vi[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(vi[i]&&question[x][i])
		{
			int tp=find(i);
			cnt[tp]+=question[x][i];
			question[x][i]=question[i][x]=0;
		}
	}
}
int main()
{
	while(1==scanf("%d",&n))
	{
		memset(v,0,sizeof(v));
		memset(vi,0,sizeof(vi));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			vt[i].clear();
		for(int i=0;i<n;i++)
		{
			int a,k,b;
			scanf("%d:(%d)",&a,&k);
			for(int j=0;j<k;j++)
			{
				scanf("%d",&b);
				v[b]=1;
				vt[a].push_back(b);
			}
		}
	//	for(int i=1;i<=n;i++)
		//	printf("%d\n",vt[i].size());
		int qu;
		scanf("%d",&qu);
		getchar();
		for(int i=0;i<qu;i++)
		{
			int a,b;
			char c;
			while(scanf("%c",&c)&&c!='(');
			scanf("%d,%d",&a,&b);
			while(scanf("%c",&c)&&c!=')');
			question[a][b]++;
			question[b][a]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(!v[i])
			{
				dfs(i,0);
				break;
			}
		}
		for(int i=1;i<=n;i++)
			if(cnt[i])
				printf("%d:%d\n",i,cnt[i]);
	}
	return 0;
}