#include<cstdio>
#include<cstring>
typedef long long LL;
LL n,m,cnt,prime[50000],is[50000],divide[50000],num[50000];
void getprime()
{
	LL tot=0;
	for(LL i=2;i<50000;i++)
	{
		if(!is[i])
		{
			prime[tot++]=i;
			for(LL j=i;j<50000;j+=i)
				is[j]=1;
		}
	}
}
void gao(LL m)
{
	cnt=0;
	for(LL i=0;prime[i]*prime[i]<=m;i++)
	{
		LL t=0;
		if(m%prime[i]==0)divide[cnt]=prime[i],t=1,m/=prime[i];
		while(m%prime[i]==0)m/=prime[i],t++;
		if(t)num[cnt]=t,cnt++;
		if(m==1)break;
	}
	if(m!=1)
		divide[cnt]=m,num[cnt]=1,cnt++;
}
LL judge(LL x,LL t)
{
	LL cnt=0;
	LL mul=x;
	while(1)
	{
		if(mul>n)break;
		cnt+=n/mul;
		mul*=x;
	}
	return cnt>=t;
}
int main()
{
	getprime();
	while(~scanf("%lld%lld",&n,&m))
	{
		if(m==0)
		{
				printf("%lld does not divide %lld!\n",m,n);
			continue;
		}
		if(m==1)
		{
			printf("%lld divides %lld!\n",m,n);
			continue;
		}
		if(n==0)
		{
			printf("%lld does not divide %lld!\n",m,n);
			continue;
		}
		LL f=1;
		gao(m);
		for(LL i=0;i<cnt;i++)
		{
			if(!judge(divide[i],num[i]))
			{
				f=0;
				break;
			}
		}
		if(f)
			printf("%lld divides %lld!\n",m,n);
		else
			printf("%lld does not divide %lld!\n",m,n);
	}
	return 0;
}
