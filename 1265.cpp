#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int p[100010];
int need[100010];
int main()
{
	char str[110];
	int cnt;
	while(gets(str)!=NULL)
	{
		p[0]=0;
		cnt=0;
		int tp=0;
		do
		{
			cnt++;
			int l=strlen(str);
			int pp=0,i,qq=0;
			for(i=0;i<l;i++)
			{
				if(str[i]==' ')break;
				pp=10*pp+str[i]-'0';
			}
			need[cnt]=pp;
			if(pp==0)p[cnt]=p[cnt-1]+1;
			else
			{
				while(str[i]==' ')i++;
				for(;i<l;i++)
				{
					if(str[i]==' ')break;
					qq=10*qq+str[i]-'0';
				}
				p[cnt]=p[cnt-1]+qq;
			}
		}
		while(gets(str)&&strcmp(str,""));
		if(tp)
		{
			puts("0");
			continue;
		}
		int ans=0;
		for(int i=2;i<=cnt;i++)
		{
			int ff=1;
			for(int j=i;j<=cnt;j++)
			{
				if(need[j]>p[j-1]-p[i-1])
				{
					ff=0;
					break;
				}
			}
			ans+=ff;
		}
		printf("%d\n",ans);
	}
}
