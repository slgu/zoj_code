#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 110
int n,m,s,d,vi[MAXN],out[MAXN];
vector<int>vt[MAXN];
void dfs(int x)
{
	vi[x]=1;
	for(int i=0;i<vt[x].size();i++)
	{
		int y=vt[x][i];
		if(vi[y])continue;
		dfs(y);
	}
}
int main()
{
	while(4==scanf("%d%d%d%d",&n,&m,&s,&d))
	{
		for(int i=0;i<n;i++)
			vt[i].clear();
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			vt[a].push_back(b);
			vt[b].push_back(a);
		}
		memset(out,0,sizeof(out));
		for(int i=0;i<n;i++)
		{
			memset(vi,0,sizeof(vi));
			vi[i]=1;
			if(!vi[s])
				dfs(s);
			if(!vi[d])
				dfs(d);
			for(int j=0;j<n;j++)
				if(!vi[j])
					out[j]=1;
		}
		int cnt=0;
		for(int i=0;i<n;i++)
			cnt+=out[i];
		printf("%d\n",cnt);
	}
	return 0;
}