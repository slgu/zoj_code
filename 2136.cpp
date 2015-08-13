#include<cstdio>
int s[1002];
int l[1002];
int maxn;
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int n;
		maxn=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s+i);
			if(i==1)
			{
				l[i]=1;
				continue;
			}
			int tp=1;
			int j;
			for(j=i-1;j>=1;j--)
			if(s[j]<s[i]&&tp<l[j]+1)
				tp=l[j]+1;
			l[i]=tp;
			if(maxn<tp)maxn=tp;
		}
		printf("%d\n",maxn);
		if(N)puts("");
	}
}