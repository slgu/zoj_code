#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 10010
int t,n,cur[MAXN],cnt[MAXN],st,ed;
struct node
{
	int a[4],step;
};
node itoa(int c)
{
	node s;
	s.step=0;
	s.a[0]=c/1000;
	s.a[1]=(c/100)%10;
	s.a[2]=(c/10)%10;
	s.a[3]=c%10;
	return s;
}
int atoi(node s)
{
	return s.a[0]*1000+s.a[1]*100+s.a[2]*10+s.a[3];
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int gao()
{
	memset(cur,0,sizeof(cur));
	memset(cnt,0,sizeof(cnt));
	queue<node>q[2];
	node s,t;
	s=itoa(st);
	cur[st]=1;
	cnt[st]=0;
	q[0].push(s);
	s=itoa(ed);
	cur[ed]=2;
	cnt[ed]=0;
	q[1].push(s);
	int sta=0;
	for(;;)
	{
	for(int index=0,count=0;count<2;index^=1,count++)
	{
		while(!q[index].empty()&&(s=q[index].front(),s.step==sta))
		{
			q[index].pop();
			for(int i=0;i<4;i++)
			{
				t=s;
				if(t.a[i]!=9)t.a[i]++;
				else t.a[i]=1;
				int num=atoi(t);
				if(!cur[num])
				{
					cur[num]=index+1;
					t.step=s.step+1;
					cnt[num]=t.step;
					q[index].push(t);
				}
				else
					if(cur[num]!=index+1)
						return cnt[num]+s.step+1;
			}
			for(int i=0;i<4;i++)
			{
				t=s;
				if(t.a[i]!=1)t.a[i]--;
				else t.a[i]=9;
				int num=atoi(t);
				if(!cur[num])
				{
					cur[num]=index+1;
					t.step=s.step+1;
					cnt[num]=t.step;
					q[index].push(t);
				}
				else
					if(cur[num]!=index+1)
						return cnt[num]+s.step+1;
			}
			for(int i=0;i<3;i++)
			{
				t=s;
				swap(t.a[i],t.a[i+1]);
				int num=atoi(t);
				if(!cur[num])
				{
					cur[num]=index+1;
					t.step=s.step+1;
					cnt[num]=t.step;
					q[index].push(t);
				}
				else
					if(cur[num]!=index+1)
						return cnt[num]+s.step+1;
			}
		}
	}
	sta++;
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&st,&ed);
		if(st==ed)
		{
			puts("0");
			continue;
		}
		printf("%d\n",gao());
	}
	return 0;
}