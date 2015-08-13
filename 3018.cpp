#include<cstdio>
#include<cstring>
#define MAXM 500000
#define MAXN 20000
struct segtree
{
	int sum;
	int l,r,a,b;
	int ch[4];
}seg[MAXM];
char str[100];
int ff,cnt;
void up(int i)
{
	seg[i].sum=0;
	for(int j=0;j<4;j++)
		if(seg[i].ch[j])
			seg[i].sum+=seg[seg[i].ch[j]].sum;
}
int get(int l,int r,int a,int b)
{
	seg[++cnt].l=l;
	seg[cnt].r=r;
	seg[cnt].a=a;
	seg[cnt].b=b;
	memset(seg[cnt].ch,0,sizeof(seg[cnt].ch));
	seg[cnt].sum=0;
	return cnt;
}
void ud(int x,int y,int i,int n)
{
	if(seg[i].l==seg[i].r&&seg[i].a==seg[i].b)
	{
		seg[i].sum+=n;
		return;
	}
	int xm=(seg[i].l+seg[i].r)>>1;
	int ym=(seg[i].a+seg[i].b)>>1;
	if(xm>=x&&ym>=y)
	{
		if(!seg[i].ch[0])
			seg[i].ch[0]=get(seg[i].l,xm,seg[i].a,ym);
		ud(x,y,seg[i].ch[0],n);
	}
	if(xm>=x&&ym<y)
	{
		if(!seg[i].ch[1])
			seg[i].ch[1]=get(seg[i].l,xm,ym+1,seg[i].b);
		ud(x,y,seg[i].ch[1],n);
	
	}
	if(xm<x&&ym>=y)
	{
		if(!seg[i].ch[2])
			seg[i].ch[2]=get(xm+1,seg[i].r,seg[i].a,ym);
		ud(x,y,seg[i].ch[2],n);
	}
	if(xm<x&&ym<y)
	{
		if(!seg[i].ch[3])
			seg[i].ch[3]=get(xm+1,seg[i].r,ym+1,seg[i].b);
		ud(x,y,seg[i].ch[3],n);
	}
	up(i);
}
int qu(int a,int b,int c,int d,int i)
{
	if(a<=seg[i].l&&seg[i].r<=b&&c<=seg[i].a&&seg[i].b<=d)
		return seg[i].sum;
	if(b<seg[i].l||seg[i].r<a||c>seg[i].b||seg[i].a>d)
		return 0;
	int t=0;
	for(int j=0;j<4;j++)
		if(seg[i].ch[j])
			t+=qu(a,b,c,d,seg[i].ch[j]);
	return t;
}
int main()
{
	while(gets(str)!=NULL)
	{
		cnt=0;
		ff=1;
		get(1,MAXN,1,MAXN);
		while(1)
		{
			if(str[0]=='E')
				break;
			if(str[0]=='I')
			{
				ff=1;
				gets(str);
				continue;
			}
			else
				if(str[0]=='Q')
				{
					ff=0;
					gets(str);
					continue;
				}
				else
				{
					int a,b,c,d;
					if(ff)
					{
						sscanf(str,"%d%d%d",&a,&b,&c);
						ud(a,b,1,c);
					}
					else
					{
						sscanf(str,"%d%d%d%d",&a,&b,&c,&d);
						printf("%d\n",qu(a,b,c,d,1));
					}
				}
			gets(str);
		}
	}
	return 0;
}
