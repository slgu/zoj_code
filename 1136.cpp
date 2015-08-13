#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int p[12];
int nu[6000];
struct node
{
	string s;
	int res;
};
string bfs()
{
	queue<node>q;
	for(int i=1;i<=m;i++)
	{
		node ss;
		ss.s+=char('0'+p[i]);
		ss.res=p[i];
		q.push(ss);
	}
	while(!q.empty())
	{
		node s=q.front();
		q.pop();	
		if(s.s=="0")
			continue;
		if(s.res==0)
			return s.s;
		if(nu[s.res]==1)
			continue;
		nu[s.res]=1;
		for(int i=1;i<=m;i++)
		{
			node t;
			t.s=s.s+char('0'+p[i]);
			t.res=(10*s.res+p[i])%n;
			if(nu[t.res])
				continue;
			q.push(t);
		}
	}
	return "0";
}
int main()
{
	while(2==scanf("%d%d",&n,&m))
	{
		memset(nu,0,sizeof(nu));
		for(int i=1;i<=m;i++)
			scanf("%d",p+i);
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		sort(p+1,p+1+m);
		cout<<bfs()<<endl;
	}
	return 0;
}
