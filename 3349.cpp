#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int p[100010],n,d,q[100010],c[100010],N,seg[500010];
map<int,int>mp;
int up(int x)
{
	seg[x]=max(seg[2*x],seg[2*x+1]);
}
int upper(int x)
{
	int l=0,r=N;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(c[m]>=x)
			r=m;
		else
			l=m+1;
	}
	return r;
}
int lower(int x)
{
	int l=0,r=N;
	while(l<r)
	{
		int m=(l+r-((l+r)>>1));
		if(c[m]<=x)
			l=m;
		else
			r=m-1;
	}
	return l;
}
int qu(int l,int r,int a,int b,int i)
{
	if(l==a&&r==b)
		return seg[i];
	int m=(l+r)>>1;
	if(m>=b)
		return qu(l,m,a,b,2*i);
	else
		if(a>m)
			return qu(m+1,r,a,b,2*i+1);
		else
			return max(qu(l,m,a,m,2*i),qu(m+1,r,m+1,b,2*i+1));
}
void ud(int l,int r,int x,int i,int va)
{
	if(l==r)
	{
		seg[i]=va;
		return;
	}
	int m=(l+r)>>1;
	if(m>=x)
		ud(l,m,x,2*i,va);
	else
		ud(m+1,r,x,2*i+1,va);
	up(i);
	return;
}
int main()
{
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		mp.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",p+i);
			q[i]=p[i];
		}
		sort(q,q+n);
		int flag=-1;
		N=0;
		for(int i=0;i<n;i++)
		{
			if(q[i]==flag);
			else
			{
				c[N++]=q[i];
				flag=q[i];
			}
		}
		N--;
		for(int i=0;i<=N;i++)
			mp[c[i]]=i;
		memset(seg,0,sizeof(seg));
		int ans=0,maxn;
		for(int i=0;i<n;i++)
		{
			int x=p[i]-d,y=p[i]+d;
			if(x<c[0])
				x=0;
			else
				x=upper(x);
			if(y>c[N])
				y=N;
			else
				y=lower(y);
			int z=mp[p[i]];
			maxn=qu(0,N,x,y,1)+1;
			if(ans<maxn)
				ans=maxn;
			ud(0,N,z,1,maxn);
		}
		printf("%d\n",ans);
	}
	return 0;
}
