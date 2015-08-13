#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int n,tmp,la,m;
int nxt[1100000],d[1100000],ff;
string str;
int gethigh(int x)
{
	if(x==ff)return 1;
	else
		return gethigh(nxt[x])+1;
}
int main()
{
	int fl=0;
	while(cin>>n,n)
	{
		if(fl)puts("");
		else fl=1;
		la=-1;
		memset(d,0,sizeof(d));
		for(int i=1;i<=(1<<(n-1));i++)
		{
			nxt[2*i-1]=2*i;
			nxt[2*i]=2*i-1;
		}
		for(int i=1;i<(1<<n);i++)
		{
			cin>>tmp;
			d[tmp]++;
			if(i==((1<<n)-1))
				ff=tmp;
			if(i%2==0)
			{
				nxt[la]=tmp;
				nxt[tmp]=la;
			}
			la=tmp;
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>tmp;
			int last=(1<<n)-((1<<(d[tmp]))-1);
			int high=gethigh(tmp);
			printf("Player %d can be ranked as high as %d or as low as %d.\n",tmp,high,last);
		}
	}
	return 0;
}
