#include<stdio.h>
int main()
{
	long n,i;
	double sum;
	printf("# Cards  Overhang\n");
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=1;i<=n;i++)
			sum+=1/(2*(double)i);
		printf("%5d%10.3f\n",n,sum);
	
	}
	return 0;
}