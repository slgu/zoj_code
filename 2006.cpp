#include<cstdio>
#include<cstring>
char s[10010];
int get()
{
	int n=strlen(s);
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		int m=s[(i+k)%n]-s[(j+k)%n];
		if(!m)
		k++;
		else
		{
			if(m>0)i+=k+1;
			else	j+=k+1;
			k=0;
			j+=(i==j);
		}
	}
	return i<j?i:j;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		printf("%d\n",get()+1);
	}
	return 0;
}