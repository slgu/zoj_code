#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n;
set<int>vt[26000];
int main()
{	
	while(~scanf("%d",&n))
	{
		for(int i=0;i<=25000;i++)vt[i].clear();
		vt[0].insert(0);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			sum+=a;
			for(int j=25000-a;j>=0;j--)
				if(vt[j].size())
				{
					for(set<int>::iterator it=vt[j].begin();it!=vt[j].end();++it)
						vt[j+a].insert(*it+1);
				}
		}
		int t=sum/2;
		for(int j=t;j>=0;j--)
		{
			if(n&1)
			{
				if(vt[j].count(n/2)||vt[j].count(n/2+1))
				{printf("%d %d\n",j,sum-j);
				break;}
			}
			else
				if(vt[j].count(n/2))
				{printf("%d %d\n",j,sum-j);break;}
		}
	}
	return 0;
}
