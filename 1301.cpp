#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
vector<int>vt[20],go[20];
int r,d,s,flag;
bool vi[11][1<<10];
struct node
{
	int id;
	int sta;
	int step;
};
node path[11][1<<10];
void print(int id,int sta)
{
	if(id==1&&sta==1)
	return;
	int _id=path[id][sta].id,_sta=path[id][sta].sta;
	print(_id,_sta);
	if(id!=_id)
	printf("- Move to room %d.\n",id);
	else
	{
		int tp=sta^_sta;
		int cnt=0;
		while(tp)
		{
			cnt++;
			tp>>=1;
		}
		if(sta&(1<<(cnt-1)))
		printf("- Switch on light in room %d.\n",cnt);
		else
		printf("- Switch off light in room %d.\n",cnt);
	}
}
void gao()
{
	queue<node>q;
	node s,t;
	s.id=1,s.sta=1,s.step=0;
	q.push(s);              
	memset(vi,0,sizeof(vi));
	vi[1][1]=1;
	while(!q.empty())
	{
		s=q.front(); 
		q.pop();
		if(s.id==r&&s.sta==(1<<(r-1)))
		{
            flag=1;
			printf("The problem can be solved in %d steps:\n",s.step);
			print(s.id,s.sta);
			printf("\n");
			return;
		}
		int i=s.id;
		int tp=s.sta;
		for(int j=0;j<vt[i].size();j++)
		{
			int k=vt[i][j];
			if(k==i)
			continue;
			int tpp=tp^(1<<(k-1));
			if(!vi[i][tpp])
			{
				vi[i][tpp]=1;
				t.id=i;
				t.sta=tpp;
				t.step=s.step+1;
				q.push(t);
				path[t.id][t.sta].id=s.id;
				path[t.id][t.sta].sta=s.sta;
				path[t.id][t.sta].step=s.step;
			}
		}
		for(int j=0;j<go[i].size();j++)
		{
			int k=go[i][j];
			if(!(tp&(1<<(k-1))))
			continue;
			if(!vi[k][tp])
			{
				vi[k][tp]=1;
				t.sta=s.sta;
				t.step=s.step+1;
				t.id=k;
				q.push(t);
				path[t.id][t.sta].id=s.id;
				path[t.id][t.sta].sta=s.sta;
				path[t.id][t.sta].step=s.step;
			}
		}
	}
	
}
int main()
{
    int pro=0;
	while(scanf("%d%d%d",&r,&d,&s),r||d||s)
	{
		int a,b;
		flag=0;
        for(int i=1;i<=r;i++)
        {
                vt[i].clear();
                go[i].clear();
        }
		for(int i=1;i<=d;i++)
		{
			scanf("%d%d",&a,&b);
			go[a].push_back(b);
			go[b].push_back(a);
		}
		for(int i=1;i<=s;i++)
		{
			scanf("%d%d",&a,&b);
			vt[a].push_back(b);
		}
		printf("Villa #%d\n",++pro);
		gao();
		if(!flag)
		printf("The problem cannot be solved.\n\n");
	}
	return 0;
}
