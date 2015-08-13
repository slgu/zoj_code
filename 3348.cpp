#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<iostream>
#include<climits>
using namespace std;
#define MAXN 20000
#define MAXM 440000
struct Dinic{
    struct edge{
        int x,y;//两个顶点
        int c;//容量
        int f;//当前流量
        edge *next,*back;//下一条边，反向边
        edge(int x,int y,int c,edge* next):x(x),y(y),c(c),f(0),next(next),back(0){}
        void* operator new(size_t, void *p){return p;}
    }*E[MAXN],*data;//E[i]保存顶点i的边表
    char storage[2*MAXM*sizeof(edge)];
    int S,T;//源、汇
   
    int Q[MAXN];//DFS用到的queue
    int D[MAXN];//距离标号，-1表示不可达
    void DFS(){
        memset(D,-1,sizeof(D));
        int head=0,tail=0;
        Q[tail++]=S;
        D[S]=0;
        for(;;){
            int i=Q[head++];
            for(edge* e=E[i];e;e=e->next){
                if(e->c==0)continue;
                int j=e->y;
                if(D[j]==-1){
                    D[j]=D[i]+1;
                    Q[tail++]=j;
                    if(j==T)return;
                }
            }
            if(head==tail)break;
        }
    }
    edge* cur[MAXN];//当前弧
    edge* path[MAXN];//当前找到的增广路
    int flow(){
        int res=0;//结果，即总流量
        int path_n;//path的大小
        for(;;){
            DFS();
            if(D[T]==-1)break;
            memcpy(cur,E,sizeof(E));
            path_n=0;
            int i=S;
            for(;;){
                if(i==T){//已找到一条增广路，增广之
                    int mink=0;
                    int delta=INT_MAX;
                    for(int k=0;k<path_n;++k){
                        if(path[k]->c < delta){
                            delta = path[k]->c;
                            mink=k;
                        }
                    }
                    for(int k=0;k<path_n;++k){
                        path[k]->c -= delta;
                        path[k]->back->c += delta;
                    }
                    path_n=mink;//回退
                    i=path[path_n]->x;
                    res+=delta;
                }
                edge* e;
                for(e=cur[i];e;e=e->next){
                    if(e->c==0)continue;
                    int j=e->y;
                    if(D[i]+1==D[j])break;//找到一条弧，加到路径里
                }
                cur[i]=e;//当前弧结构，访问过的不能增广的弧不会再访问
                if(e){
                    path[path_n++]=e;
                    i=e->y;
                }
                else{//该节点已没有任何可增广的弧，从图中删去，回退一步
                    D[i]=-1;
                    if(path_n==0)break;
                    path_n--;
                    i=path[path_n]->x;
                }
            }
        }
        return res;
    }
    int cut(int* s){
        int rst=0;
        for(int i=0;i<MAXN;++i)
            if(D[i]==-1&&E[i])
                s[rst++]=i;
        return rst;
    }
    void init(int _S,int _T){
        S=_S,T=_T;
        data=(edge*)storage;
        memset(E,0,sizeof(E));
    }
    void add_edge(int x,int y,int w){//加进一条x至y容量为w的边，需要保证0<=x,y<MAXN，0<w<=INT_MAX
        E[x]=new((void*)data++) edge(x,y,w,E[x]);
        E[y]=new((void*)data++) edge(y,x,0,E[y]);
        E[x]->back = E[y];
        E[y]->back = E[x];
    }
};
map<string,int>mp;
int d[55],g[55][55];
int n,m,p,cnt;
string a,b,c;
Dinic dinic;
int get(string &s)
{
	if(mp.count(s)>0)
	{
		return mp[s];
	}
	else
		return mp[s]=cnt++;
}
int main()
{
	while(2==scanf("%d%d",&n,&m))
	{
		memset(d,0,sizeof(d));
		mp.clear();
		memset(g,0,sizeof(g));
		mp["DD"]=0;
		dinic.init(0,n);
		cnt=1;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			int x=get(a);
			int y=get(b);
			if(c=="win")
				d[x]++;
			else
				d[y]++;
		}	
		scanf("%d",&p);
		for(int i=0;i<p;i++)
		{
			cin>>a>>b;
			int x=get(a);
			int y=get(b);
			if(x>y)
				swap(x,y);
			d[x]++;
			g[x][y]++;
		}
		int sum=0;
		for(int i=1;i<n;i++)
		{
			dinic.add_edge(0,i,d[i]);
			dinic.add_edge(i,n,d[0]-1);
			sum+=d[i];
			for(int j=i+1;j<n;j++)
			{
				if(g[i][j]>0)
					dinic.add_edge(i,j,g[i][j]);
			}
		}
	printf("%s\n",dinic.flow()==sum?"Yes":"No");
	}
	return 0;
}
