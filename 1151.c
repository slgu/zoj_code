#include<stdio.h>
char * reverse(char *a);
int main()
{
	int n1,n2;
	char str[100],*p;
	scanf("%d",&n1);
	while(n1--)
	{
		scanf("%d",&n2);
		getchar();
		while(n2--)
		{
			gets(str);
			p=str;
			while(*p)
			{
				p=reverse(p);
				while(*p&&*++p==' ');
			}
			printf("%s\n",str);
	
		}
		if(n1)
              printf("\n");
	}
	return 0;
}
char * reverse(char * a)
{
	char *p=a,*q;
	char temp;
	while(*p!=' '&&*p)
		p++;
	q=p-1;
	while(a<q)
	{
		temp=*a;
		*a=*q;
		*q=temp;
		a++;
		q--;
	}
	return p;
}
