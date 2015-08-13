#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n1;
	scanf("%d",&n1);
	char str[300];
	char str1[300];
	int flag[300];
	int i,j,z;
	int flag1;
	char *p;
	getchar();
	while (n1--)
	{
		memset(flag,0,sizeof(flag));
		gets(str);
		j=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]!=' ')
				str1[j++]=str[i];
		}
		str1[j]='\0';
		p=str1;
		p=strstr(p,"-(");
		while(p!=NULL)
		{
			flag[p+1-str1]=1;
			z=0;
			p=p+2;
			int k;
			flag1=0;
			for(k=0;z<=0;k++)
			{
				if(*(p+k)=='+'||*(p+k)=='-')
					flag1=1;
				if(*(p+k)=='(')
					z--;
				if(*(p+k)==')')
					z++;
			}
			k--;
			if(flag1==1)
				flag[p+k-str1]=1;
			else
			{
				flag[p-1-str1]=0;
			}
			p=strstr(p,"-(");
		}
		for(i=0;str1[i]!='\0';i++)
			if((str1[i]=='('||str1[i]==')')&&flag[i]==0)
				str1[i]=' ';
		for(i=0;str1[i]!='\0';i++)
			if(str1[i]!=' ')
				printf("%c",str1[i]);
		printf("\n");
	}
	return 0;
}