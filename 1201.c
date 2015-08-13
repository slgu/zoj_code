#include<stdio.h>
#include<string.h>
int a[500];
int b[500];
int main()
{
	int n1,i,j,count;
	char c[2];
	scanf("%d",&n1);
	while(n1!=0)
	{
		memset(b,0,500*sizeof(int));
		memset(a,0,500*sizeof(int));
		scanf("%s",&c);
		if(*c=='P')
		{
			for(i=1;i<=n1;i++)
				scanf("%d",&a[i]);
			for(i=2;i<=n1;i++)	
				for(j=1;j<i;j++)
					if(a[j]>a[i])
						b[a[i]]++;
			for(i=1;i<n1;i++)
			printf("%d ",b[i]);
			printf("%d\n",b[i]);
		}
		else if(*c=='I')
		{
			for(i=1;i<=n1;i++)
				scanf("%d",&b[i]);
			for(i=1;i<=n1;i++)
			{
				count=0;
				for(j=1;j<=n1;j++)
				{
					if(a[j]!=0)
					count++;
					else if(j-1-count==b[i])
					break;
				}
				a[j]=i;
			}	
			for(i=1;i<n1;i++)
			printf("%d ",a[i]);
			printf("%d\n",a[i]);
		}
      scanf("%d",&n1);
	}
	return 0;
}
