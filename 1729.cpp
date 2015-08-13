#include<cstdio>
#include<cstring>
int t;
int n;
char s[200010];
int get()
{
	int i=1,j=2,k=0;
	while(i<=n&&j<=n&&k<=n)
	{
		int m=s[i+k]-s[j+k];
		if(!m)
			k++;
		else
		{
			if(m>0)
			i+=k+1;
			else
			j+=k+1;
			k=0;
			j+=(i==j);
		}
	}
	return i<j?i:j;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
		s[i+n]=s[i];
		printf("%d\n",get()-1);
	}
}