#include<stdio.h>
#include<string.h>
char str[110];
int dp[110][110][110];
int main()
{
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			for(int z=0;z<=100;z++)
			{
				if(j==1&&z-i==1)
					dp[i][j][z]=1;
				else
				{
					if(j>=1&&z>=1)
					dp[i][j][z]=dp[i][j-1][z-1];
				}
			}		
	while(scanf("%s",str)!=EOF)
	{
		int p=-1,q=-1,flag=0;
		int l=strlen(str);
		for(int i=0;i<l;i++)
		{
			if(str[i]=='Z')
			{
				if(p==-1)
					p=i;
				else
				{
					flag=1;
					break;
				}
			}
			if(str[i]=='J')
			{
				if(q==-1)
					q=i;
				else
				{
					flag=1;
					break;
				}
			}
		}
		if(flag||p==-1||q==-1||!dp[p][q-p-1][l-1-q])
			printf("Wrong Answer\n");
		else
			printf("Accepted\n");
	}
	return 0;
}
