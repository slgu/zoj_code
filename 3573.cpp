#include<cstdio>
#include<cstring>
int n,a,b,c;
struct segtree{int l,r,lp,rp,maxn,f;}seg[64000];
void build(int l,int r,int i)
{
	seg[i].l=l,seg[i].r=r;
	seg[i].lp=l,seg[i].rp=r;
	seg[i].maxn=seg[i].f=0;
	if(l==r)
		return;
	int m=(l+r)>>1;
	build(l,m,2*i);
	build(m+1,r,2*i+1);
}
void down(int x)
{
	if(seg[x].f)
	{
		seg[2*x].f+=seg[x].f;
		seg[2*x+1].f+=seg[x].f;
		seg[2*x+1].maxn+=seg[x].f;
		seg[2*x].maxn+=seg[x].f;
		seg[x].f=0;
	}
}
void up(int x)
{
	if(seg[2*x+1].maxn==seg[2*x].maxn)
	{
		seg[x].maxn=seg[2*x].maxn;
		seg[x].lp=seg[2*x].lp;
		seg[x].rp=seg[2*x+1].rp;
	}
	else
		if(seg[2*x+1].maxn>seg[2*x].maxn)
		{
			seg[x].maxn=seg[2*x+1].maxn;
			seg[x].lp=seg[2*x+1].lp;
			seg[x].rp=seg[2*x+1].rp;
		}
		else
		{
			seg[x].maxn=seg[2*x].maxn;
			seg[x].lp=seg[2*x].lp;
			seg[x].rp=seg[2*x].rp;
		}
}
void ud(int l,int r,int x,int i)
{
	if(l==seg[i].l&&r==seg[i].r)
	{
		seg[i].f+=x;
		seg[i].maxn+=x;
		return;
	}
	down(i);
	int m=(seg[i].l+seg[i].r)>>1;
	if(r<=m)
		ud(l,r,x,2*i);
	else
		if(l>m)
			ud(l,r,x,2*i+1);
		else
		{
			ud(l,m,x,2*i);
			ud(m+1,r,x,2*i+1);
		}
	up(i);
}
int main()
{
	while(~scanf("%d",&n))
	{
		build(0,n,1);
		while(scanf("%d%d%d",&a,&b,&c),a!=-1)
		{
			ud(a,b,c,1);
		}
		printf("%d %d\n",seg[1].lp,seg[1].rp);
	}
	return 0;
}
