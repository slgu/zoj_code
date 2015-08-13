#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int T,n,m;
char s[110];
vector<int>vt[9];
struct trie
{
	int cnt;
	trie * nxt[26];
};
trie * init(int num)
{
	trie * p=new trie;
	p->cnt=num;
	for(int i=0;i<26;i++)
		p->nxt[i]=NULL;
	return p;
}
struct node
{
	string s;
	int pro;
}tot[110];
void insert(trie *p,char *s,int num)
{
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		int j=s[i]-'a';
		if(p->nxt[j]==NULL)
		{
			p->nxt[j]=init(num);
		}
		else
		{
			p->nxt[j]->cnt+=num;
		}
		p=p->nxt[j];
	}
}
void dfs(trie *p,char *s,int x,int l,string st)
{
	if(x!=0)
	{
		if(p->cnt>tot[x].pro)
		{
			tot[x].pro=p->cnt;
			tot[x].s=st;
		}
	}
	int j=s[x]-'0'-1;
	if(j==0)
		return;
	for(int i=0;i<vt[j].size();i++)
	{
		int y=vt[j][i];
		char c=y+'a';
		if(p->nxt[y]==NULL)
		continue;
		dfs(p->nxt[y],s,x+1,l,st+c);
	}
}
int main()
{
	int tt=0;
	for(int i=0;i<3;i++)
	vt[1].push_back(i);
	for(int i=3;i<6;i++)
	vt[2].push_back(i);
	for(int i=6;i<9;i++)
	vt[3].push_back(i);
	for(int i=9;i<12;i++)
	vt[4].push_back(i);
	for(int i=12;i<15;i++)
	vt[5].push_back(i);
	for(int i=15;i<19;i++)
	vt[6].push_back(i);
	for(int i=19;i<22;i++)
	vt[7].push_back(i);
	for(int i=22;i<26;i++)
	vt[8].push_back(i);
	scanf("%d",&T);
	while(T--)
	{		
		printf("Scenario #%d:\n",++tt);
		trie *p=init(1);
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			int c;
			scanf("%s%d",s,&c);
			insert(p,s,c);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			for(int w=1;w<=105;w++)
				tot[w].pro=0;
			scanf("%s",s);
			int l=strlen(s);
			dfs(p,s,0,l,"");
			for(int i=1;i<l;i++)
			{
				if(tot[i].pro)
				cout<<tot[i].s<<endl;
				else
				cout<<"MANUALLY"<<endl;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
