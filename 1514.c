#include<stdio.h>
#include<string.h>
int a[10010];
int main()
{
	int n,m,i,c,count;
	while(scanf("%d%d",&n,&m)&&(m||n))
	{
		count=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=m;i++)
		{
			scanf("%d",&c);
			a[c]++;
		}
		for(i=1;i<=n;i++)
			if(a[i]>1)
				count++;
		printf("%d\n",count);
	}
	return 0;
}