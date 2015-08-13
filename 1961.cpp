#include<cstdio>
#include<cstring>
int c,s,prime[]={2,3,5,7,11,13};
int eular(int x)
{
	if(x==1)return 1;
	int rep=x;
	for(int i=0;prime[i]*prime[i]<=x;i++)
	{
		if(x%prime[i]==0)
		{
			rep-=rep/prime[i];
			x/=prime[i];
		}
		while(x%prime[i]==0)x/=prime[i];
		if(x==1)break;
	}
	if(x!=1)rep-=rep/x;
	return rep;
}
int pow(int x,int y)
{
	int t=1;
	while(y)
	{
		if(y&1)t=t*x;
		x=x*x;
		y>>=1;
	}
	return t;
}
int main()
{
	while(scanf("%d%d",&c,&s),s||c)
	{
		int i;
		int ans=0;
		for(i=1;i*i<s;i++)
		{
			if(s%i==0)
			{
				ans+=pow(c,i)*eular(s/i);
				ans+=pow(c,s/i)*eular(i);
			}
		}
		if(i*i==s)
			ans+=pow(c,i)*eular(s/i);
		if(s%2)
		{
			ans+=s*pow(c,(1+(s-1)/2));
		}
		else
		{
			ans+=s/2*pow(c,s/2);
			ans+=s/2*pow(c,s/2+1);
		}
		ans/=2*s;
		printf("%d\n",ans);
	}
	return 0;
}
