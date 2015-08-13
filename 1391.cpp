#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int t,n,ans;
int hash[20000];
struct node
{
	int y1,y2,x;
	friend bool operator<(node a,node b)
	{
		return a.x<b.x;
	}
} p[20000];
int seg[90000];
vector<int>vt[20000];
void down(int i)
{
	if(seg[i]!=-1)
	{
		seg[2*i]=seg[2*i+1]=seg[i];
		seg[i]=-1;
	}
	return;
}
void ud(int l,int r,int a,int b,int i,int x)
{
	if(l==a&&r==b)
	{
		seg[i]=x;
		return;
	}
	down(i);
	int m=(a+b)>>1;
	if(m>=r)
	ud(l,r,a,m,2*i,x);
	else
	if(l>m)
	ud(l,r,m+1,b,2*i+1,x);
	else
	{
	ud(l,m,a,m,2*i,x);
	ud(m+1,r,m+1,b,2*i+1,x);
	}
	
}
void qu(int l,int r,int a,int b,int i,int x)
{
	if(seg[i]!=-1)
	{
		int c=seg[i];
		if(hash[c]!=x)
		{
			vt[c].push_back(x);
			hash[c]=x;
		}
		return;
	}
	if(a==b)
	return ;
	int m=(a+b)>>1;
	if(r<=m)
	qu(l,r,a,m,2*i,x);
	else
	if(l>m)
	qu(l,r,m+1,b,2*i+1,x);
	else
	{
		qu(l,m,a,m,2*i,x);
		qu(m+1,r,m+1,b,2*i+1,x);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(hash,-1,sizeof(hash));
		memset(seg,-1,sizeof(seg));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p[i].y1,&p[i].y2,&p[i].x);
			p[i].y1*=2;
			p[i].y2*=2;
			vt[i].clear();
		}
		sort(p+1,p+1+n);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			qu(p[i].y1,p[i].y2,0,16000,1,i);
			ud(p[i].y1,p[i].y2,0,16000,1,i);
		}
		for(int i=1;i<=n;i++)
		for(int j=0;j<vt[i].size();j++)
		{
			int k=vt[i][j];
			for(int a=0;a<vt[i].size();a++)
			for(int b=0;b<vt[k].size();b++)
				if(vt[i][a]==vt[k][b])
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
