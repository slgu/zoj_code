#include<stdio.h>
#include<string.h>
char a[110],b[110],c[110],d[110];
int i,la,lb,j;
char x[220];
void dfs(int k,int in,int out);
int main()
{
	while(scanf("%s%s",a,b)!=EOF)
	{
		la=strlen(a);
		lb=strlen(b);
		printf("[\n");	
		i=1;
		dfs(1,0,0);
		printf("]\n");
	}
	return 0;
}
void dfs(int k,int in,int out)
{
	if(out==la)
	{
		for(j=1;j<=2*la;j++)
			printf("%c ",x[j]);
		printf("\n");
	}
	else
	{
		if(a[in]!='\0')
		{
			c[i]=a[in];
			x[k]='i';
			i++;
			dfs(k+1,in+1,out);
			i--;
		}
		if(i-1>0&&c[i-1]==b[out])
		{
			i--;
			x[k]='o';
			d[k]=c[i];
			dfs(k+1,in,out+1);
			c[i]=d[k];
			i++;
		}


	}
}