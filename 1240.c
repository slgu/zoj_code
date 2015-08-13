#include<stdio.h>
int main()
{
	int n,i=1;
	char *s;
	char a[100];
	scanf("%d",&n);
	while(i<=n)
	{
		scanf("%s",a);
		s=a;
		while(*s)
		{
			*s=(*s-'A'+1)%26+'A';
			s++;
		}
		printf("String #%d\n",i);
		printf("%s\n",a);
		printf("\n");
		i++;
	}
	return 0;
}