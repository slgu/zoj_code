#include<stdio.h>
#include<string.h>
char s[1000001];
int main(void)
{
	int find,i,j,len;
	while( scanf("%s",s) != EOF )
	{
		if(strcmp(s,".")==0) break;
		len = strlen(s);
		for( i = 1;i <= len;i++)
		{
			if( len % i != 0 ) continue;
			for(j = i,find=1;j<len;j++)
				if( s[j%i] != s[j] ) 
				{
					find=0;
					break;
				}
			if( find ) break;
		}
		printf("%d\n",len/i);
	}
	return 0;
}