#include<cstdio>
#include<cmath>
int n;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int n1;
		scanf("%d",&n1);
		int i=sqrt(n1);
		printf("%d\n",i);
	}
	return 0;
}