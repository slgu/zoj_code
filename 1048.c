#include<stdio.h>
int main()
{
	int i=0;
	double j=0,p;
	for(;i<12;i++)
	{
		scanf("%lf",&p);
		j+=p;
	}
	j/=12;
	printf("$%.2f\n",j);
     return 0;
}
