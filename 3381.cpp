#include<cstdio>
#define MAXN 50010
#define max(a,b) ((a)>(b))?(a):(b)
int n,s[MAXN],x[MAXN],y[MAXN];
int seg[4*MAXN];
int dp[MAXN];
void up(int x)
{
	seg[x]=max(seg[2*x],seg[2*x+1]);
}
void build(int l,int r,int i)
{
	seg[i]=0;
	if(l==r)
		return;
	int m=(l+r)>>1;
	build(l,m,2*i);
	build(m+1,r,2*i+1);
}
void ud(int l,int r,int pos,int i,int x)
{
	if(l==r&&l==pos)
	{
		seg[i]=x;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=pos)
		ud(l,mid,pos,2*i,x);
	else
		ud(mid+1,r,pos,2*i+1,x);
	up(i);
}
int qu(int l,int r,int a,int b,int i)
{
	if(l==a&&r==b)
		return seg[i];
	int mid=(l+r)>>1;
	if(mid>=b)
		return qu(l,mid,a,b,2*i);
	else
		if(a>mid)
			return qu(mid+1,r,a,b,2*i+1);
		else
			return max(qu(l,mid,a,mid,2*i),qu(mid+1,r,mid+1,b,2*i+1));
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		build(1,n,1);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",s+i,x+i,y+i);
		dp[n]=s[n];
		for(int i=n-1;i>=1;i--)
		{
			ud(1,n,i+1,1,dp[i+1]);
			if(i+y[i]-1<=n)
			dp[i]=s[i]+qu(1,n,i+x[i],i+y[i]-1,1);
			else
			if(i+x[i]<=n)
			dp[i]=s[i]+qu(1,n,i+x[i],n,1);
			else
			dp[i]=s[i];
		}
		printf("%d\n",dp[1]);
	}
	return 0;
}