#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c;
	int i=1;
	while(scanf("%lf%lf%lf",&a,&b,&c))
	{
		if(a==0&&b==0&&c==0)
			break;
		printf("Triangle #%d\n",i);	
		if(a==-1)
		{
			a=c*c-b*b;
			if(a<=0)
				printf("Impossible.\n");
			else
				printf("a = %.3f\n",sqrt(a));
		}
		if(b==-1)
		{
			b=c*c-a*a;
			if(b<=0)
				printf("Impossible.\n");
			else
				printf("b = %.3f\n",sqrt(b));
		}		
		if(c==-1)
		{
			c=sqrt(b*b+a*a);
			printf("c = %.3f\n",c);
		}
		printf("\n");
		i++;
	}
	return 0;
}