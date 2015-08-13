#include<cstdio>
#include<cstring>
int m,l,n,sum;
int c[2200];
int dp[2200];
int path[2200];
int ans[2200];
int main()
{
	while(scanf("%d%d",&m,&l),m||l)
	{
		scanf("%d",&n);
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",c+i);
			sum+=c[i];
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=sum;j>=0;j--)
				if(dp[j])
				{
					if(!dp[j+c[i]])
					{
						dp[j+c[i]]=1;
						path[j+c[i]]=i;
					}
				}
		}
		int extra=m+l-sum;
		int ff=0;
		for(int i=m-extra;i<=m;i++)
		{
			if(dp[i])
			{
				ff=1;
				int cnt=0,tp=i;
				while(tp)
				{
					int tmp=path[tp];
					tp-=c[tmp];
					cnt++;
				}
				printf("%d",cnt);
				tp=i;
				cnt=0;
				while(tp)
				{
					int tmp=path[tp];
					tp-=c[tmp];
					ans[cnt++]=tmp;
				}
				for(int i=cnt-1;i>=0;i--)
					printf(" %d",ans[i]+1);
				puts("");
				break;
			}
		}
		if(!ff)
			printf("Impossible to distribute\n");
	}
	return 0;
}
