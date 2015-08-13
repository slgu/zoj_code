#include<stdio.h>
#include<string.h>
int main()
{
	char str[1024]={0};
	char *p;
	int n,k;
	while(1)
	{
        scanf("%s",str);
		p=str;
        n=0; 
        if(*p=='0')
			break;
		while(*p)
		{
			n+=*p-'0';
			p++;
		}
		while(n>=10)
		{
			k=0;
			while(n!=0)
			{
				k+=n%10;
				n/=10;
			}
			n=k;
		}
		printf("%d\n",n);
	}
	return 0;
}