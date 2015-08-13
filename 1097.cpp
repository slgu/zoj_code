#include<cstdio>
#include<cstring>
int n;
int g[52][52],d[52];
char s[300];
int cnt;
void dfs(int x)
{
     for(;cnt<strlen(s);cnt++)
     {
                                  if(s[cnt]==' ')
                                  continue;
                                  if(s[cnt]==')')
                                  return;
                                  if(s[cnt]=='(')
                                  {
                                                 int sum=0;
                                                 cnt++;
                                                 while(s[cnt]==' ')
                                                 cnt++; 
                                                 while(cnt<strlen(s)&&s[cnt]>='0'&&s[cnt]<='9')
                                                 {
                                                                                         sum=sum*10+s[cnt]-'0';
                                                                                         cnt++;
                                                 }
                                                 if(x!=0)
                                                 {
                                                         g[x][sum]=g[sum][x]=1;
                                                         d[x]++;
                                                         d[sum]++;
                                                 }
                                                         dfs(sum);
                                  }
     }
     return;
}
int main()
{
	while(gets(s))
	{
		cnt=0;
		n=0;
		memset(g,0,sizeof(g));
		memset(d,0,sizeof(d));
		dfs(0);
	/*	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
		{
                if(g[i][j])
                printf("%d %d\n",i,j);
                }
                */
		int ff=0;
		for(int i=1;i<=50;i++)
		if(d[i])
        n++;
		for(int c=1;c<=n-1;c++)
		{
			int tp,index=60;
			for(int i=1;i<=50;i++)
			{
				if(d[i]==1&&i<index)
						index=i;
			}
			d[index]=0;
			for(int i=1;i<=50;i++)
			{
				if(g[index][i])
				{
					g[index][i]=0;
					g[i][index]=0;
					if(ff==0)
					{
						ff=1;
						printf("%d",i);
					}
					else
						printf(" %d",i);
					d[i]--;
				}
			}
		}
		puts("");
	}
	return 0;
}