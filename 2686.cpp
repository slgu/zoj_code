#include<cstdio>
int t,n;
int p[25];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",p+i);
		int flag=0;
		for(int i=0;i<n;i++)
			if(p[i]==0)
			{
				flag+=((i+1)%2==0);
				break;
			}
		for(int i=0;i<n;i++)
			if(p[n-i-1]==0)
			{
				flag+=((i+1)%2==0);
				break;
			}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}