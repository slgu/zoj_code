#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int Hash[9]={1,1,2,6,24,120,720,5040,40320};
int mp[3][3],vi[500000],fa[500000];
char s[5][5];
int des=0;
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
char f_dic[]={'q','d','r','l','u'};
struct status
{
	int maze[3][3];
	int h,g;
	int x,y;
	int hash;
	friend bool operator<(status a,status b)
	{
		return (a.h!=b.h)?a.h>b.h:a.g>b.g;
	}
	bool in()
	{
		return x>=0&&x<3&&y>=0&&y<3;
	}
};
void swap(int &a,int &b)
{
	int tp=b;
	b=a;
	a=tp;
}
int abs(int x)
{
	return x>0?x:-x;
}
int KT(int g[][3])
{
	int a[9];
	int k=0,sum=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[k++]=g[i][j];
	for(int i=0;i<9;i++)
	{
		int cnt=0;
		for(int j=i+1;j<9;j++)
			if(a[j]<a[i])
				cnt++;
		sum+=(cnt*Hash[8-i]);
	}
	return sum;
}
int high(int g[][3])
{
	int sum=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			sum+=(abs(i-(g[i][j]-1)/3)+abs(j-(g[i][j]-1)%3));
		}
	return sum;
}
void pat(int g[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			printf("%d ",g[i][j]);
		puts("");
	}
	puts("");
	getchar();
}
int cut(int g[][3])
{
	int a[9];
	int k=0,cnt=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[k++]=g[i][j];
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
		if(a[i]!=9&&a[j]!=9&&a[i]>a[j])
			cnt++;
	return cnt&1;
}
int Astar()
{
	memset(vi,0,sizeof(vi));
	priority_queue<status>q;
	status s,t;
	memcpy(s.maze,mp,sizeof(mp));
	s.hash=KT(mp);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(mp[i][j]==9)
			{
				s.x=i,s.y=j;
				break;
			}
		}
	s.g=0;
	s.h=high(mp);
	q.push(s);
	vi[s.hash]=1;
	fa[s.hash]=-1;
	while(!q.empty())
	{
	//	pat(s.maze);
	//	printf("%d\n",s.hash),getchar();
		s=q.top();
		q.pop();
		for(int i=0;i<4;i++)
		{
			t=s;
			t.x=s.x+dx[i];
			t.y=s.y+dy[i];
			if(!t.in())
				continue;
			swap(t.maze[t.x][t.y],t.maze[s.x][s.y]);
			t.hash=KT(t.maze);
			t.h=high(t.maze);
			if(!vi[t.hash])
			{
				vi[t.hash]=i+1;
				fa[t.hash]=s.hash;
				t.g++;
				q.push(t);
			}
			if(t.hash==des)
			return t.g;
		}
	}
	return -1;
}
void print(int x)
{
	if(fa[x]==-1)
		return;
	print(fa[x]);
	printf("%c",f_dic[vi[x]]);
}
int main()
{
	char tmp[2];
	while(scanf("%s",tmp)!=EOF)
	{
		int i=1;
		if(tmp[0]=='x')
			mp[0][0]=9;
		else
			mp[0][0]=tmp[0]-'0';
		for(;i<=8;i++)
		{
			scanf("%s",tmp);
			if(tmp[0]=='x')
				mp[0][i]=9;
			else
				mp[0][i]=tmp[0]-'0';
		}
		if(cut(mp))
		{
			printf("unsolvable\n");
			continue;
		}
		int ans=Astar();
		if(ans==-1)
			printf("unsolvable\n");
		else
		{
			print(des);
			puts("");
		}
	}
	return 0;
}