#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#define MAXN 10003
#define MAXM 200033
using namespace std;
int n,m,dfn[MAXN],low[MAXN],head[MAXN],cnt,v[MAXN],ans[MAXN],tot,sum,ok[MAXM];
struct EDGE
{
	int to,nxt,tag,cur,db;
}edge[MAXM];
void init()
{
	cnt=tot=sum=0;
	memset(head,-1,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(v,0,sizeof(v));
	memset(ok,0,sizeof(ok));
}
void add(int x,int y,int i)
{
	int j;
	for(j=head[x];j!=-1;j=edge[j].nxt)
	{
		if(edge[j].to==y)
			break;
	}
	if(j!=-1)
	{
		edge[j].db=1;
		return;
	}
	edge[cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].tag=0;
	edge[cnt].cur=i;
	edge[cnt].db=0;
	head[x]=cnt++;
}
void addedge(int x,int y,int i)
{
	add(x,y,i);
	add(y,x,i);
}
int dfs(int x)
{
	v[x]=1;
	if(x==n-1)
		return 1;
	for(int j=head[x];j!=-1;j=edge[j].nxt)
	{
		int y=edge[j].to;
		if(v[y])
			continue;
		edge[j].tag=1;
		edge[j^1].tag=1;
		v[y]=1;
		if(dfs(y))return 1;
		edge[j].tag=0;
		edge[j^1].tag=0;
	}
	return 0;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	for(int j=head[x];j!=-1;j=edge[j].nxt)
	{
		int y=edge[j].to;
		if(!dfn[y])
		{
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(edge[j].tag&&low[y]>dfn[x]&&!edge[j].db)
			{
				if(ok[edge[j].cur])
					continue;
				ok[edge[j].cur]=1;
				ans[sum++]=edge[j].cur;
			}
		}
		else
			if(y!=fa)
				low[x]=min(low[x],dfn[y]);
	}
}
int main()
{
	while(2==scanf("%d%d",&n,&m))
	{
		int a,b;
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b,i);
		}
		dfs(0);
		tarjan(0,-1);
		sort(ans,ans+sum);
		printf("%d\n",sum);
		
			for(int i=0;i<sum;i++)
			{
				if(i==0)
				printf("%d",ans[i]);
				else
				printf(" %d",ans[i]);
			}
			puts("");	
	}
	return 0;
}