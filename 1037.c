#include<stdio.h>
int main()
{
	int k,m,n;
	if(scanf("%d",&k)==EOF||k<=0)
		return 0;
	int i;
	for(i=1;i<=k;i++)
	{
		if(scanf("%d%d",&m,&n)==EOF||m<=1||m>=50||n<=1||n>=50)
			return 0;
		printf("Scenario #%d:\n",i);
		if(m*n%2==0)
			printf("%.2f\n\n",m*n+0.00);
		else
			printf("%.2f\n\n",m*n+0.41);

	
	}
	return 0;
}
	