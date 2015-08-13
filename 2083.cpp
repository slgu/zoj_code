#include<cstdio>
#include<cstring>
int sg[55];
int SG(int x)
{
	if(sg[x]!=-1)return sg[x];
	int v[51];
	memset(v,0,sizeof(v));
	for(int l=0;l<=x-2;l++)
		v[SG(l)^SG(x-l-2)]=1;
	for(int i=0;;i++)
		if(v[i]==0)
			return sg[x]=i;
}
int n;
int main()
{
	memset(sg,-1,sizeof(sg));
	sg[0]=0;
	sg[1]=0;
	sg[2]=1;
	while(scanf("%d",&n)!=EOF)
	{
		int a,ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			ans^=SG(a);
		}
		printf("%s\n",ans==0?"No":"Yes");
	}
	return 0;
}
