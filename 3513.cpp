#include<cstdio>
#include<cstring>
int mp[100000],x,y;
int dfs(int i,int j){
	int pos=(i-1)*y+j;
	if(i==0||j==0)
		return 0;
	if(mp[pos]!=-1)
		return mp[pos];
	int f=1;
	for(int z=1;i-z*j>=0;z++)
		if(dfs(i-z*j,j))
		{
			f=0;
			break;
		}
	for(int z=1;j-z*i>=0;z++)
		if(dfs(i,j-z*i))
		{
			f=0;
			break;
		}
	return mp[pos]=f;
}
int main()
{
	int por=0;
	while(2==scanf("%d%d",&x,&y)){
		memset(mp,-1,sizeof(mp));
		printf("Case #%d:\n",++por);
		for(int i=1;i<=x;i++)
			for(int j=1;j<=y;j++)
					dfs(i,j);
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
				printf("%s",(mp[(i-1)*y+j]==0)?"H":"P");
			puts("");
		}
	}
	return 0;
}
