#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,maxn;
int p[30];
int v[30];
int flag;
int  search(int va)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(p[m]==va)
			return 1;
		if(p[m]<va)
			l=m+1;
		else
			r=m-1;
	}
	return 0;
}
void dfs(int i,int cnt,int l,int va)
{
	if(cnt==l)
	{
		if(search(va))
		{
			flag=1;
			int f=0;
			for(int j=0;j<i;j++)
				if(v[j])	
				{
					if(f)
						printf("+%d",p[j]);
					else
					{
						f=1;
						printf("%d",p[j]);
					}
				}
			printf("=%d\n",va);
		}
		return;
	}	
	if(i>=n)
	return;
	if(va+(l-cnt)*p[i]>maxn)
	return;
	v[i]=1;
	dfs(i+1,cnt+1,l,va+p[i]);
	v[i]=0;
	dfs(i+1,cnt,l,va);
}
int main()
{	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=0;
		for(int i=0;i<n;i++)
			scanf("%d",p+i);
		sort(p,p+n);
		maxn=p[n-1];
		for(int l=2;l<=n-1;l++)
		{
			memset(v,0,sizeof(v));
			dfs(0,0,l,0);
		}
		if(!flag)
			printf("Can't find any equations.\n");
			puts("");
	}
	return 0;
}