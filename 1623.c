#include<stdio.h>
#include<string.h>
int T,n;
char str[1000000],t[1000];
int main()
{
	scanf("%d",&T);
	while(T--)
	{	
		scanf("%d",&n);
		int i,j,k;
		getchar();
		memset(str,0,sizeof(str));
		for(i=0;i<n;i++)
		{
			gets(t);
			strcat(str,t);
			strcat(str,"\n");
		}
		int l=strlen(str);
		int cnt=0;
		for(i=0;i<l;i++)
		{
			if(str[i]==str[i+1]&&str[i]=='/')
			{
				int j;
				for(j=i+2;str[j]!='\n';j++)
					if(str[j]>='a'&&str[j]<='z')
						str[j]+='A'-'a';
				i=j;
				cnt++;
			}
			else
				if(str[i]=='/'&&str[i+1]=='*')
				{
					int j;
					for(j=i+2;j<l;j++)
						if(str[j]=='*'&&str[j+1]=='/')
							break;
					if(j<l)
					{
						cnt++;
						for(k=i+2;k<j;k++)
							if(str[k]>='a'&&str[k]<='z')
								str[k]+='A'-'a';
						i=j+2;
					}
					else
						i=i+1;
				}
		}
		printf("%d\n%s\n",cnt,str);
	}
	return 0;
}
