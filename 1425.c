#include<stdio.h>
#include<string.h>
int f[102][102];
int num1[102];
int num2[102];
int n,m;
int maxn(int a,int b)
{
	return a>b?a:b;
}
int search1(int i,int b);
int search2(int i,int b);
int main()
{
	int t,i,j,a,b;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&num1[i]);
		for(i=1;i<=m;i++)
			scanf("%d",&num2[i]);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				f[i][j]=maxn(f[i-1][j],f[i][j-1]);
				a=search1(i,num2[j]);
				b=search2(j,num1[i]);
				if(num1[i]!=num2[j]&&a>0&&b>0)
					f[i][j]=maxn(f[i][j],f[a-1][b-1]+2);
			}
		printf("%d\n",f[n][m]);
	}
	return 0;

}
int search1(int i,int b)
{
	int j;
	for(j=i-1;j>=1;j--)
		if(num1[j]==b)
			return j;
	return -1;
}
int search2(int i,int b)
{
	int j;
	for(j=i-1;j>=1;j--)
		if(num2[j]==b)
			return j;
	return -1;
}