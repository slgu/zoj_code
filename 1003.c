#include<stdio.h>
#include<string.h>
int visit[110];
int dfs(int m,int t);
int vdfs(int m,int t);
int n;
int main()
{
	int m,i;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(visit,0,sizeof(visit));
		if(m>n)
		{
			int t=m;
			m=n;
			n=t;
		}
			
			if(!vdfs(m,2))
			{
				printf("%d\n",n);
				continue;
			}
		if(dfs(m,2))
			printf("%d\n",n);
		else
			printf("%d\n",m);
	}
	return 0;
}
int dfs(int m,int t)
{
	if(m==1)
		if(vdfs(n,2))
			return 1;
	int i;
	for(i=t;i<=100;i++)
		if(m%i==0&&!visit[i])
		{
			visit[i]=1;
			if(dfs(m/i,i+1))
			{
				
				visit[i]=0;
				return 1;
			}
			visit[i]=0;
		}

	return 0;
}
int vdfs(int m,int t)
{
	if(m==1)
		return 1;
	int i;
	for(i=t;i<=100;i++)
		if(m%i==0&&!visit[i])
		{
			visit[i]=1;
			if(vdfs(m/i,i+1))
			{
				visit[i]=0;
				return 1;
			}
			visit[i]=0;
		}
	return 0;
}