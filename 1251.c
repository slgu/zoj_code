#include<stdio.h>
int a[100];
int jd(int a,int b)
{
	return a>b?(a-b):(b-a);
}
int main()
{
	int n,i,sum,ave,j=0;
	while(scanf("%d",&n),n)
	{
		j++;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		ave=sum/n;
		sum=0;
		for(i=0;i<n;i++)
			sum+=jd(a[i],ave);
		sum/=2;
		printf("Set #%d\n",j);
		printf("The minimum number of moves is %d.\n\n",sum);
	}

	return 0;
}