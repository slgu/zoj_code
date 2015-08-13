#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
typedef long long LL;
using namespace std;
struct node
{
	int y,l;
	friend bool operator<(node a,node b)
	{return a.l>b.l;}
};
vector<node>vt[10010];
const int inf=1000000;
const LL MOD=10000000000LL;
int n,m,q,d[10010],vi[10010];
LL cnt[10010],cntt[10010];
long long Mul(long long lhs,long long rhs)
{
    long long lhs2=lhs%100000;
    long long rhs2=rhs%100000;
    return ((lhs/100000*rhs2+rhs/100000*lhs2)*100000+lhs2*rhs2)%MOD;
}
void dij()
{
	for(int i=0;i<n;i++)d[i]=inf;
	d[0]=0;
	memset(cnt,0,sizeof(cnt));
	memset(vi,0,sizeof(vi));
	priority_queue<node>q;
	node s,tt;
	s.y=0;
	s.l=0;
	q.push(s);
	cnt[0]=1;
	while(!q.empty())
	{
		s=q.top();
		q.pop();
		int x=s.y;
		int w=s.l;
		if(vi[x])continue;
		vi[x]=1;
		for(int i=0;i<vt[x].size();i++)
		{
			int y=vt[x][i].y;
			int l=vt[x][i].l;
			if(d[y]>w+l)
			{
				d[y]=w+l;
				tt.y=y;
				tt.l=d[y];
				q.push(tt);
				cnt[y]=cnt[x];
			}
			else
				if(d[y]==w+l)
				{
					cnt[y]=(cnt[y]+cnt[x])%MOD;
				}
		}
	}
}
LL dfs(int x)
{
	if(cntt[x]!=-1)return cntt[x];
	LL sum=1;
	for(int i=0;i<vt[x].size();i++)
	{
		int y=vt[x][i].y;
		if(y==x)continue;
		int l=vt[x][i].l;
		if(d[y]==d[x]+l)
		sum=(sum+dfs(y))%MOD;
	}
	return cntt[x]=sum;
}
int main()
{
	while(3==scanf("%d%d%d",&n,&m,&q))
	{
		int a,b,c;
		for(int i=0;i<n;i++)
		{
			vt[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			node s;
			s.y=b;
			s.l=c;
			vt[a].push_back(s);
		}
		dij();
		memset(cntt,-1,sizeof(cntt));
		for(int i=0;i<q;i++)
		{
			int p;
			scanf("%d",&p);
			LL tot=Mul(cnt[p],dfs(p));
			printf("%010lld\n",tot);
		}
	}
	return 0;
}
