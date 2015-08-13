#include<cstdio>
#include<cstring>
char s[90];
int dp[100],n;
int gao(int a,int m,int c,int n)
{
	while(s[a]=='0'&&m)a++,m--;
	while(s[c]=='0'&&n)c++,n--;
	if(m<n)
	return 1;
	if(n<m)
	return 0;
	for(int i=0;i<m;i++)
	{
		if(s[c+i]>s[a+i])return 1;
		if(s[c+i]<s[a+i])return 0;
	}
	return 0;
}
void print(int x)
{
	if(x>n)
	return;
	if(x!=1)
	printf(",");
	for(int i=1;i<=dp[x];i++)
	printf("%c",s[x+i-1]);
	print(x+dp[x]);
}
int main()
{
	while(scanf("%s",s+1)&&strcmp(s+1,"0"))
	{
		dp[1]=1;
		n=strlen(s+1);
		for(int i=2;i<=n;i++)
		{
			dp[i]=i;
			for(int j=i-1;j>=0;j--)
			{
				if(gao(j-dp[j]+1,dp[j],j+1,i-j))
				{
					dp[i]=i-j;
					break;
				}
			}
		}
		int l=n-dp[n]+1;
		dp[l]=dp[n];
		for(int k=l-1;k>=1;k--)
		{
			dp[k]=-1;
			if(s[k]=='0')
			{
				dp[k]=dp[k+1]+1;
				continue;
			}
			for(int j=l-1;j>=k;j--)
			{
				if(gao(k,j-k+1,j+1,dp[j+1]))
				{
					dp[k]=j-k+1;
					break;
				}
			}
		}
		print(1);
		printf("\n");
	}
	return 0;
}