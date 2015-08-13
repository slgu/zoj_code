#include<iostream>
using namespace std;
int main()
{
	int n,a[40],sum,ave;
	while(cin>>n,n)
	{
		sum=0,ave=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%2)
		{
			cout<<"No equal partitioning.\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			ave+=a[i];
			if(ave==sum/2)
			{
				cout<<"Sam stops at position "<<i<<" and Ella stops at position "<<i+1<<".\n";
				break;
			}
			if(ave>sum/2)
			{
				cout<<"No equal partitioning.\n";
				break;
			}
		}
	}
	return 0;
}