#include<cstdio>
#include<cstring>
int n,u,d;
int main()
{
	while(scanf("%d%d%d",&n,&u,&d),n||u||d)
	{
		n-=u;
		int k=n/(u-d);
		if(n%(u-d))k++;
		k*=2;
		k++;
		printf("%d\n",k);
	}
	return 0;
}
