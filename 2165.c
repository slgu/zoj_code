#include<stdio.h>
#include<string.h>
char s[30][30];
int visit[30][30];
void dfs(int i,int j);
int count;
int main()
{
	int w,h,i,j;
	while(1)
	{
		count=1;
		memset(s,0,sizeof(s));
		memset(visit,0,sizeof(visit));
		scanf("%d%d",&w,&h);
		if(w==0&&h==0)
			break;
		for(i=1;i<=h;i++)
			scanf("%s",(s[i]+1));
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				if(s[i][j]=='@')
					break;
			}
			if(s[i][j]=='@')
				break;
		}
		visit[i][j]=1;
		dfs(i,j);
		printf("%d\n",count);
	}
	return 0;
}
void dfs(int i,int j)
{
	if(s[i][j-1]=='.'&&visit[i][j-1]==0)
	{
		visit[i][j-1]=1;
		count++;
		dfs(i,j-1);
	}
	if(s[i+1][j]=='.'&&visit[i+1][j]==0)
	{
		visit[i+1][j]=1;
		count++;
		dfs(i+1,j);
	}
	if(s[i][j+1]=='.'&&visit[i][j+1]==0)
	{
		visit[i][j+1]=1;
		count++;
		dfs(i,j+1);
	}
	if(s[i-1][j]=='.'&&visit[i-1][j]==0)
	{
		visit[i-1][j]=1;
		count++;
		dfs(i-1,j);
	}

}
