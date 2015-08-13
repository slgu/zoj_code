#include<stdio.h>
#include<string.h>
int a[100];
int top();
int main()
{
	int n,q,i,c,j,temp,result;
	while (1)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&q);
		if(n==0&&q==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&c);
			for(j=0;j<c;j++)
			{
				scanf("%d",&temp);
				a[temp]++;
			}
		}
		result=top();
		if(a[result]<q)
			printf("0\n");
		else
			printf("%d\n",result);
	}
	return 0;
}
int top()
{
	int i,max=a[0],index;
	for(i=0;i<100;i++)
		if(a[i]>max)
		{
			max=a[i];
			index=i;
		}
	return index;
}