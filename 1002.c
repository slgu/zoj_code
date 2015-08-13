#include<stdio.h> 
#include<string.h>
char a[10][10];
int visit[10][10];
int judge(int i,int j);
int dfs(int i,int j);
int count,n;
int main()
{
	int i,j,k;
	while(scanf("%d",&n),n)
	{
		count=0;
		k=0;
		memset(visit,0,sizeof(visit));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(a[i][j]=='.')
					{
						visit[i][j]=1;
						count=dfs(i,j);
						if(count>k)
							k=count;
						count=0;
						memset(visit,0,sizeof(visit));
					}
		printf("%d\n",k);	

	}
	return 0;
}
int judge(int i,int j)
{
	int m;
	for(m=i;m<=n;m++)
		if(a[m][j]=='.'&&visit[m][j])
			return 1;
		else if(a[m][j]!='.')
			break;
	for(m=i;m>=0;m--)
		if(a[m][j]=='.'&&visit[m][j])
			return 1;
		else if(a[m][j]!='.')
			break;
	for(m=j;m<=n;m++)
		if(a[i][m]=='.'&&visit[i][m])
			return 1;
		else if(a[i][m]!='.')
			break;
	for(m=j;m>=0;m--)
		if(a[i][m]=='.'&&visit[i][m])
			return 1;
		else if(a[i][m]!='.')
			break;
	return 0;
}
int dfs(int i,int j)
{
	int p,q,k,max=1;
	for(p=1;p<=n;p++)
		for(q=1;q<=n;q++)
		
			if(a[p][q]=='.'&&!judge(p,q)&&!visit[p][q])
		{
			
			visit[p][q]=1;
			k=dfs(p,q)+1;
			if(k>max)
				max=k;
		}
	visit[i][j]=0;
	return max;
}	
