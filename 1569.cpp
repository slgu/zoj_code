#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int num[10010],sum[5100];
int main()
{
	while(cin>>n>>m)
	{
		num[0]=0;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			num[i]=(num[i-1]+a)%m;
			sum[num[i]]++;
		}
		int ans=0;
		for(int i=0;i<m;i++)
			if(sum[i]>=2)
				ans+=sum[i]*(sum[i]-1)/2;
		ans+=sum[0];
		cout<<ans<<endl;
	}
	return 0;
}
