#include<cstdio>
#include<cstring>
int n;
const int inf=9999999;
char s[110];
int dp[110][110],p[110][110];
void print(int i,int j)
{
	if(i>j)
		return;
	if(i==j)
	{
		if(s[i]=='('||s[i]==')')
			printf("()");
		else
			printf("[]");
		return;
	}
	else if(p[i][j]==-1)
	{
		printf("%c",s[i]);
		print(i+1,j-1);
		printf("%c",s[j]);
		return;
	}
	else
	{
		int k=p[i][j];
		print(i,k);
		print(k+1,j);
		return;
	}
}
int main()
{
	scanf("%d",&n);
	getchar();
	getchar();
	while(n--)
	{
		gets(s);
		if(s[0]=='\0')
		{
			puts("");
			if(n)
				printf("\n");
			continue;
		}
		int l=strlen(s);
	for(int i=0;i<l;i++)
		for(int j=0;j<l;j++)
		{
			if(i>j)
				dp[i][j]=0;
			else
			if(i==j)
				dp[i][j]=1;
			else
				dp[i][j]=inf;
		}
	for(int len=2;len<=l;len++)
		for(int i=0;i+len-1<l;i++)
		{
			int j=i+len-1;
			if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
			{
				dp[i][j]=dp[i+1][j-1];
				p[i][j]=-1;
			}
			for(int k=i;k<j;k++)
			{
				if(dp[i][j]>dp[i][k]+dp[k+1][j])
				{
					dp[i][j]=dp[i][k]+dp[k+1][j];
					p[i][j]=k;
				}
			}
		}
		print(0,l-1);
		printf("\n");
		if(n)
		{
			printf("\n");
			getchar();
		}
	}
	return 0;
}