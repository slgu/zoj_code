#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,m;
map<string,string>mp;
map<string,int>cnt;
map <string,int>::iterator it; 
int main()
{
	string a,b;
	while(cin>>n)
	{
		cnt.clear();
		mp.clear();
        while( getchar()!='\n' ) continue;  
		for(int i=1;i<=n;i++)
		{
			getline(cin,a);
			getline(cin,b);
			mp[a]=b;
		}
		cin>>m; 
		while( getchar()!='\n' ) continue;  
		for(int i=1;i<=m;i++)
		{
			getline(cin,a);
			if(mp[a].size()!=0)
			cnt[a]++;
		}
		int flag=0,temp;
		int maxn=0;
		string ans;
		for(it=cnt.begin();it!=cnt.end();++it)
		{
			temp=it->second;
			if(temp>maxn)
			{
				flag=1;
				maxn=temp;
				ans=it->first;
			}
			else if(temp==maxn)
			flag=0;
		}
		if(!flag)
		cout<<"tie";
		else
		cout<<mp[ans];
		cout<<endl;
	}
    return 0;
}
