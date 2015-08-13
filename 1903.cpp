#include<cstdio>
#include<cstring>
const int inf=99999999;
int n,m;
int u[20],d[20],mp[20][20];
int min(int a,int b)
{
	return a<b?a:b;
}
void floyd()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				if(i==j||i==k||j==k)
					continue;
				if(mp[i][k]==inf||mp[k][j]==inf)
					continue;
				mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
			}
}
int gao()
{
	int i,j,k,mx=inf;
	for(i=0;i<n;i++)
		if(!u[i])
			break;
	if(i==n)
		return 0;
	u[i]=1;
	for(int j=i+1;j<n;j++)
		if(!u[j])
			u[j]=1,mx=min(mx,gao()+mp[i][j]),u[j]=0;
	u[i]=0;
	return mx;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		int ans=0;
		memset(u,0,sizeof(u));
		memset(d,0,sizeof(d));
		scanf("%d",&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				mp[i][j]=inf;
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--,b--;
			ans+=c;
			mp[a][b]=min(mp[a][b],c);
			mp[b][a]=mp[a][b];
			d[a]++,d[b]++;
		}
		floyd();
		for(int i=0;i<n;i++)
			if(!(d[i]&1))u[i]=1;
		printf("%d\n",ans+gao());
	}
	return 0;	
}
