#include<cstdio>
#include<algorithm>
using namespace std;
const int size=250;
typedef int chunk[size];
chunk p[210];
int oo,n,m,a[50010],x,y,k;
char s[3];
int getpos(int d,int k)
{
	int l=0;
	int r=size-1;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(p[d][m]==k)return m;
		else
			if(p[d][m]<k)l=m+1;
			else
					r=m-1;
	}
	return -1;
}
int getcnt(int x,int y,int k)
{
	int s=0;
	while(x%size&&x<=y)
	{
		if(a[x]<=k)s++;
		x++;
	}
	while((y+1)%size&&y>=x)
	{
		if(a[y]<=k)s++;
		y--;
	}	
	if(x>y)return s;
	int l=x/size;
	int r=y/size;
	for(int i=l;i<=r;i++)
	{
		int ll=0;
		int rr=size-1;
		while(ll<rr)
		{
			int m=(ll+rr+1)>>1;
			if(p[i][m]<=k)ll=m;
			else
				rr=m-1;
		}
		if(p[i][ll]<=k)s+=ll+1;
		else
				s+=ll;
	}
	return s;
}
int main()
{
	scanf("%d",&oo);
	while(oo--)
	{
		scanf("%d%d",&n,&m);
		int c;
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
			p[i/size][i%size]=a[i];
		}
		for(int i=0;i<n/size;i++)
				sort(p[i],p[i]+size);		
		for(int i=0;i<m;i++)
		{
			scanf("%s",s);
			if(*s=='Q')
			{
				scanf("%d%d%d",&x,&y,&k);
				x--;
				y--;
				int l=0,r=1000000000;
				while(l<r)
				{
					int m=(l+r+1)>>1;
					if(getcnt(x,y,m)<k)l=m;
					else
						r=m-1;
				}
				printf("%d\n",r+1);
			}
			else
			{
				scanf("%d%d",&x,&y);
				x--;
				int d=x/size;
				int t=getpos(d,a[x]);
				a[x]=y;
				while(t+1<size&&y>p[d][t+1])
				{
					p[d][t]=p[d][t+1];
					t++;
				}
				while(t-1>=0&&y<p[d][t-1])
				{
					p[d][t]=p[d][t-1];
					t--;
				}
				p[d][t]=y;
			}
		}
	}
	return 0;
}