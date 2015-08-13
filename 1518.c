/*DFS*/
#include<stdio.h>
#include<string.h>
int dfs(int j);
char str[50];
int graph[1001][1001];
int visit[1001]; 
int color[1001];
int sum[2];
int maxn(int a,int b)
{
	return a>b?a:b;
}
int n;
int main()
{
	int i,j,num,q;
	while(scanf("%d",&n),n)
	{
		num=0;
		memset(graph,-1,sizeof(graph));
		memset(visit,0,sizeof(visit));
		memset(color,-1,sizeof(color));
		for(i=1;i<=n;i++)
			graph[i][i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s%d%s%s",str,&j,str,str);
			if(str[0]=='f')
			{
				if(graph[i][j]==0)
					goto end;
				else
				{
					graph[i][j]=1;
					graph[j][i]=1;
				}
			}
			else
			{
				if(graph[i][j]==1)
					goto end;
				else
				{
					graph[i][j]=0;
					graph[j][i]=0;
				}
			}
		}
		for(i=1;i<=n;i++)
			if(!visit[i])
			{
				sum[0]=1;sum[1]=0;
				color[i]=0;
				visit[i]=1;
				if(dfs(i))
					goto end;
				num+=maxn(sum[0],sum[1]);
			}
		printf("%d\n",num);
		continue;
end:printf("Inconsistent\n");
	}
	return 0;
}
int dfs(int j)
{
	int i;
	for(i=1;i<=n;i++)
		if(!visit[i])
		{
			if(graph[i][j]==0)
			{
				if(color[i]==-1)
				{
					visit[i]=1;
					color[i]=color[j];
					sum[color[i]]++;
					dfs(i);
				}
				if(color[i]!=-1)
				{
					if(color[i]!=color[j])
						return 1;
				}
			}
			if(graph[i][j]==1)
			{
				if(color[i]==-1)
				{
					visit[i]=1;
					color[i]=color[j]^1;
					sum[color[i]]++;	
					dfs(i);
				}
				if(color[i]!=-1)
				{
					if(color[i]==color[j])
						return 1;
				}

			}

		}
		else 
		{
			if(color[i]!=color[j]&&graph[j][i]==0)
				return 1;
			if(color[i]==color[j]&&graph[i][j]==1)
				return 1;

		}

	return 0;
}