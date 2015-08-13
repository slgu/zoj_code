/*最大堆，最小堆实现优先队列的经典*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int a[30010],b[30010];
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		priority_queue< int , vector< int > , greater< int > > pmin; 
		priority_queue< int > pmax;
		cin>>m>>n;
		for(int i=1;i<=m;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		int i=1,j=1;
		while(i<=n)
		{
			if(!pmax.empty()&&a[j]<pmax.top())
			{
				pmin.push(pmax.top());
				pmax.pop();
				pmax.push(a[j]);
			}
			else
				pmin.push(a[j]);
			j++;
			while(j-1==b[i])
			{
				cout<<pmin.top()<<endl;
				i++;
				pmax.push(pmin.top());
				pmin.pop();
			}
		}
		if(t)
			cout<<endl;
	}
}