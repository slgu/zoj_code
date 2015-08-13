#include<cstdio>
#include<cstring>
char s[30];
int v[30];
int dfs(int x)
{
	for(int i=1;i<=6;i++)
	{
		if(v[i]==4)
			continue;
		if(i+x>31)
			continue;
		v[i]++;
		if(!dfs(x+i))
		{
			v[i]--;
			return 1;
		}
		v[i]--;
	}
	return 0;
}
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		memset(v,0,sizeof(v));
		int l=strlen(s);
		int sum=0;
		for(int i=0;i<l;i++)
		{
			sum+=s[i]-'0';
			v[s[i]-'0']++;
		}
		int ans=(l%2)^dfs(sum);
		printf("%s %c\n",s,ans?'A':'B');	
	}
	return 0;
}
