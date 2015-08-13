#include<cstdio>
#include<cstring>
#define MAXN 10000
int seg[4*MAXN],n,cnt[MAXN],col[MAXN];
void down(int x)
{
	if(seg[x]!=-1)
	{
		seg[2*x]=seg[2*x+1]=seg[x];
		seg[x]=-1;
	}
}
void ud(int le,int re,int a,int b,int i,int x)
{
	if(le==a&&re==b)
	{
		seg[i]=x;
		return;
	}
	down(i);
	int mid=(le+re)>>1;
	if(mid>=b)
		ud(le,mid,a,b,2*i,x);
	else
		if(mid<a)
			ud(mid+1,re,a,b,2*i+1,x);
		else
		{
			ud(le,mid,a,mid,2*i,x);
			ud(mid+1,re,mid+1,b,2*i+1,x);
		}
}
void dfs(int l,int r,int i)
{
	if(seg[i]!=-1)
	printf("%d %d %d\n",l,r,seg[i]);
	if(l==r)return;
	int m=(l+r)>>1;
	dfs(l,m,2*i);
	dfs(m+1,r,2*i+1);
}
void cal(int l,int r,int x)
{
	if(seg[x]!=-1)
	{
		for(int i=l;i<=r;i++)
			col[i]=seg[x];
		return;
	}
	if(l==r)
		return;
	int m=(l+r)>>1;
	cal(l,m,2*x);
	cal(m+1,r,2*x+1);
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(seg,-1,sizeof(seg));
		memset(col,-1,sizeof(col));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a++;
			ud(1,MAXN,a,b,1,c);
		}
		//dfs(1,MAXN,1);
		cal(1,MAXN,1);
		int t=-1;
		for(int i=1;i<MAXN;i++)
		{
			if(col[i]==-1)
			{
				t=-1;
				continue;
			}
			if(t!=col[i])
			{
				cnt[col[i]]++;
				t=col[i];
			}
		}
		for(int i=0;i<MAXN;i++)
			if(cnt[i])
				printf("%d %d\n",i,cnt[i]);
		puts("");
	}
	return 0;
}