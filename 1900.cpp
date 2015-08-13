#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int t,p;
char str[1000];
set<int>vt[110];
set<set<int> >m;
int main()
{
	while(scanf("%d%d",&p,&t)!=EOF)
	{
		int a,b;
		m.clear();
		for(int i=1;i<=p;i++)
			vt[i].clear();
		getchar();
		while(gets(str)&&strcmp(str,""))
		{
			sscanf(str,"%d %d",&a,&b); 
			vt[a].insert(b);
		}
		for(int i=1;i<=p;i++)
			m.insert(vt[i]);
		printf("%d\n",m.size());
	}
	return 0;
}
