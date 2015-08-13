#include<cstdio>
#include<cstring>
#include<vector>
#include<memory.h>
using namespace std;
vector<int>fa[510];
int n,m,st,ed;
const int INF=9999999;
int mp[510][510];
int va[510];
int dis[510];
int vi[510];
int choose()
{
	int minn=INF,index=-1;
	for(int i=1;i<=n;i++)
		if(!vi[i])
		{
			if(minn>dis[i])
			{
				index=i;
				minn=dis[i];
			}
		}
	return index;
}
int sum,maxvalue;
int path[510],in,moni[510],fin;
void dfs(int x,int value)
{
//	printf("ues %d \n",x);
	if(x==st)
	{
		sum++;
		moni[++in]=st;
		if(value>maxvalue)
		{
			maxvalue=value;
			memcpy(path,moni,sizeof(moni));
			fin=in;
		}
		--in;
		return;
	}
	for(int i=0;i<fa[x].size();i++)
	{
		moni[++in]=x;
		dfs(fa[x][i],va[fa[x][i]]+value);
		--in;
	}
}
int main()
{
	while(scanf("%d%d%d%d",&n,&m,&st,&ed)!=EOF)
	{
		st++;
		ed++;
		memset(path,0,sizeof(path));
		memset(moni,0,sizeof(moni));
		memset(vi,0,sizeof(vi));
		for(int i=1;i<=n;i++)
			fa[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					mp[i][j]=0;
				else
					mp[i][j]=INF;
			}
		for(int i=1;i<=n;i++)
			scanf("%d",va+i);
		for(int i=1;i<=m;i++)
		{
			int a,b,l;
			scanf("%d%d%d",&a,&b,&l);
			a++,b++;
			mp[a][b]=mp[b][a]=l;
		}	
		for(int i=1;i<=n;i++)
		{	
			if(i==st)
				dis[i]=0;
			else
			{
				dis[i]=mp[st][i];
				fa[i].push_back(st);
			}
		}
		vi[st]=1;
		for(int i=1;i<=n-1;i++)
		{
			int u=choose();
			vi[u]=1;
			for(int i=1;i<=n;i++)
				if(!vi[i])
				{
					if(mp[u][i]==INF)
						continue;
					else
						if(dis[i]>dis[u]+mp[u][i])
						{
							dis[i]=dis[u]+mp[u][i];
							fa[i].clear();
							fa[i].push_back(u);
						}
						else
							if(dis[i]==dis[u]+mp[u][i])
							{
								fa[i].push_back(u);
							}
				}
		}
	/*	for(int i=1;i<=n;i++)
			printf("%d ",dis[i]);
		puts("");
		*/
	/*	for(int i=1;i<=n;i++)
		{
			for(int j=0;j<fa[i].size();j++)
				printf("%d ",fa[i][j]);
			puts("");
		}*/
		sum=in=0;
		maxvalue=-1;
		dfs(ed,va[ed]);
		printf("%d %d\n",sum,maxvalue);
		for(in=1;;in++)
			if(path[in]==0)
				 break;
		for(int i=fin;i>=1;i--)
		{
			if(i==fin)
				printf("%d",path[i]-1);
			else
				printf(" %d",path[i]-1);
		}
		printf("\n");
	}
	return 0;
}