#include<stdio.h>
int main()
{
	int i,n1,z;
	float x,y;
	scanf("%d",&n1);
	for(i=1;i<=n1;i++)
	{
		scanf("%f%f",&x,&y);
		z=(int)(3.14*(x*x+y*y)/100)+1;
		printf("Property %d: This property will begin eroding in year %d.\n",i,z);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
