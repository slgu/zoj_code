#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#define MAXN 110
using namespace std;
int n,ans,dfn[MAXN],low[MAXN],tot;
char str[MAXN];
vector<int>vt[MAXN];
set<int>st;
int get(char *s)
{
	char *p=s;
	while(*p!=' '&&*p!=0)p++;
	while(*p==' ')p++;
	if(*p==0)
		return -1;
	else
		return p-s;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	for(int i=0;i<vt[x].size();i++)
	{
		int y=vt[x][i];
		if(!dfn[y])
		{
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if((x!=1&&low[y]>=dfn[x])||(x==1&&dfn[y]>2))
				st.insert(x);
				
		}
		else
			if(y!=fa)
				low[x]=min(low[x],dfn[y]);
	}
}
int main()
{
	while(scanf("%d",&n),n)
	{
		int x;
		for(int i=1;i<=n;i++)
			vt[i].clear();
		while(scanf("%d",&x),x)
		{
			gets(str);
			char *p=str;
			while(1)
			{
				int number=get(p);
				if(number==-1)
					break;
				int tp;
				sscanf(p+number,"%d",&tp);
				vt[x].push_back(tp);
				vt[tp].push_back(x);
				p=p+number;
			}
		}
		ans=tot=0;
		st.clear();
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		tarjan(1,0);
		printf("%d\n",st.size());
	}
	return 0;
}