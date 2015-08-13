#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,cnt,head[10010],tot,dfs[20010],low[20010],bridge[10010],ans;
struct EDGE
{
	int to,nxt,tag,qu;
}edge[200010];
void add(int x,int y,int c)
{
	int i;
	for(i=head[x];i!=-1;i=edge[i].nxt)
	{
		if(edge[i].to==y)
		break;
	}
	if(i!=-1)
	{
		edge[i].tag=1;
		return;
	}
	edge[cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].tag=0;
	edge[cnt].qu=c;
	head[x]=cnt++;
	return;
}
void gao(int x,int y,int c)
{
	add(x,y,c);
	add(y,x,c);
}
void tarjan(int x,int fa)
{
	dfs[x]=low[x]=++tot;
	for(int j=head[x];j!=-1;j=edge[j].nxt)
	{
		int y=edge[j].to;
		if(!dfs[y])
		{
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfs[x]&&!edge[j].tag)
			{
				bridge[++ans]=edge[j].qu;
			}
		}
		else
		if(y!=fa)
		low[x]=min(low[x],dfs[y]);
	}
	return;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		tot=0;
		ans=0;
		memset(head,-1,sizeof(head));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			gao(x,y,i);
		}
		memset(dfs,0,sizeof(dfs));
		memset(low,0,sizeof(low));
		tarjan(1,0);
		printf("%d\n",ans);
		sort(bridge+1,bridge+1+ans);
		if(ans)
		{
		for(int i=1;i<=ans;i++)
		{
			if(i==1)
			printf("%d",bridge[i]);
			else
			printf(" %d",bridge[i]);
		}
		puts("");
         }
		if(t)
		puts("");
	}
	
	return 0;
}