#include<cstdio>
#include<map>
#include<iterator>
#include<algorithm>
typedef long long LL;
using namespace std;
LL N,S,W;
LL a[100010],p[100010];
int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
	scanf("%lld%lld%lld",&N,&S,&W);
	int g = S;
	for (int i=0; i<N; i++) { 
   			 a[i] = g;
   	if( a[i] == 0 ) { a[i] = g = W; }
    if( g%2 == 0 ) { g = (g/2); }
    else           { g = (g/2) ^ W; }
	}
	p[0]=a[0];
	for(int i=1;i<N;i++)
		p[i]=p[i-1]^a[i];
	LL ans=(N+1)*N/2;
	int l=1;
	sort(p,p+N);
	for(int i=1;i<N;i++)
	{
		if(p[i]==p[i-1])
			l++;
		else
		{
			ans-=l*(l-1)/2;
			if(p[i-1]==0)
			ans-=l;
			l=1;
		}
	}
	ans-=(l-1)*l/2;
	printf("%lld\n",ans);
	}
}
