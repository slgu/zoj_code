#include<stdio.h>	
#include<string.h>
void reverse(char * a);
int main()
{
	char a[110];
	char b[110];
	int i,j,m,n;
	char *c="0123456789abcdefghij";
	while(scanf("%s%s",a,b)!=EOF)
	{
		i=0;
		j=0;
		reverse(a);
		reverse(b);
		while(a[i]&&b[i])
		{
			m=strchr(c,a[i])-c;
			n=strchr(c,b[i])-c;
			a[i]=*(c+(m+n+j)%20);
			j=(m+n+j)/20;
			i++;
		}
		if(a[i])
			while(a[i])
		{
			m=strchr(c,a[i])-c;
			a[i]=*(c+(m+j)%20);
			j=(m+j)/20;
			i++;
		}
	    else if(b[i])
			while(b[i])
		{
			m=strchr(c,b[i])-c;
			a[i]=*(c+(m+j)%20);				
			j=(m+j)/20;
			i++;
		}
		if(j!=0)
			a[i++]='1';
			a[i]=0;
		reverse(a);
		printf("%s\n",a);
	
	}	

	return 0;
}
void reverse(char *a)
{
	char * p=a;
	char temp;
	while(*p)
		p++;
		p--;
	while(a<p)
	{
	    temp=*a;
		*a=*p;
		*p=temp;
		a++;
		p--;
	}	
}
	