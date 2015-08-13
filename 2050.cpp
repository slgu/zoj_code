#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char str[5][5];
int t,vi[1<<16],st;
void deal(int &x,int pos)
{
	if(pos-4>=0)
		x^=(1<<(pos-4));
	if(pos+4<16)
		x^=(1<<(pos+4));
	if(pos%4>0)
		x^=(1<<(pos-1));
	if(pos%4<3)
		x^=(1<<(pos+1));
}
struct node
{
	int x;
	int step;
};
int gao()
{
	memset(vi,0,sizeof(vi));
	queue<node>q;
	node s,t;
	s.x=st,s.step=0;
	vi[st]=1;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		if(s.x==0||s.x==((1<<16)-1))
			return s.step;
		q.pop();
		for(int i=0;i<16;i++)
		{
			int num=s.x;
			num^=(1<<i);
			deal(num,i);
			if(!vi[num])
			{
				t.x=num;
				vi[num]=1;
				t.step=s.step+1;
				q.push(t);
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<4;i++)
			scanf("%s",str+i);
		st=0;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				if(str[i][j]=='b')
					st|=(1<<(4*i+j));
			}
		int ans=gao();
		if(ans==-1)
			printf("Impossible\n");
		else
			printf("%d\n",ans);
		if(t)
			puts("");
	}
	return 0;
}
