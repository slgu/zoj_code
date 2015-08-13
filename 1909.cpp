#include<cstdio>
#include<cstring>
int s[25],v[25];
int sum,n;
int dfs(int x,int step,int va)
{
	if(step==4)
		return 1;
	if(va==sum)
		return dfs(1,step+1,0);
	if(x>n)
		return 0;
	if(v[x])
		return dfs(x+1,step,va);
	else
	{
		v[x]=1;
		if(dfs(x+1,step,va+s[x]))
			return 1;
		v[x]=0;
		return dfs(x+1,step,va);
	}
	return 0;
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		sum=0;
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s+i);
			sum+=s[i];
		}
		if(sum%4)
		{
			printf("no\n");
			continue;
		}
		sum/=4;
		printf("%s\n",(dfs(1,1,0)==0)?"no":"yes");
	}
	return 0;
}