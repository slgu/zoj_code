

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define maxn 105
#define maxm 100005


int s,t;
int n,m;
int dist[maxn],low[maxn],tot,eh[maxn],pre[maxn],cnt[maxn],cur[maxn];
int maz[maxn][maxn], mapp[maxn][maxn];
 
struct Edge {
    int u,v,cap,flow,next;
}et[maxm];
 
void init() {
    tot=0;
    memset(eh,-1,sizeof(eh));
}
 
void add(int u,int v,int cap,int flow) {
    Edge E={u,v,cap,flow,eh[u]};
    et[tot]=E;
    eh[u]=tot++;
}
 
void addedge(int u,int v,int cap) {
    add(u,v,cap,0),add(v,u,0,0);
}
 
int isap(int s,int t, int n) {
    int u,v,now;
    memset(dist,0,sizeof(dist));
    memset(low,0,sizeof(low));
    for (u=0; u<=n; u++) cur[u]=eh[u];
    int maxflow=0;
    u=s;
    low[s]=inf,cnt[0]=n;
    while (dist[s]<n) {
        for (now=cur[u]; now!=-1; now=et[now].next)
            if (et[now].cap-et[now].flow && dist[u]==dist[v=et[now].v]+1) break;
        if (now!=-1) {
            cur[u]=pre[v]=now;
            low[v]=min(low[u],et[now].cap-et[now].flow);
            u=v;
            if (u==t) {
                for (; u!=s; u=et[pre[u]].u) {
                    et[pre[u]].flow+=low[t];
                    et[pre[u]^1].flow-=low[t];
                }
                low[s]=inf;
                maxflow+=low[t];
            }
        } 
        else {
            if (--cnt[dist[u]]==0) break;
            dist[u]=n;
            cur[u]=eh[u];
            for (now=eh[u]; now!=-1; now=et[now].next)
                if (et[now].cap-et[now].flow && dist[u]>dist[et[now].v]+1) 
                    dist[u]=dist[et[now].v]+1;
             cnt[dist[u]]++;
             if(u!=s) u=et[pre[u]].u;
         }
     }
     return maxflow;
 }
 
 void floyd() {
     for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
           for(int j=0; j<n; j++)
                if(maz[k][j]!=inf && maz[i][k]!=inf)
                    maz[i][j]=min(maz[i][j],maz[i][k]+maz[k][j]);
     return ;
 }
 

int main() {
    while(~scanf("%d",&n)) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d",&maz[i][j]);
                if (maz[i][j]==-1) maz[i][j]=inf;
                if(i==j) maz[i][j]=0;
                mapp[i][j]=maz[i][j];
            }
        }
        scanf("%d%d",&s,&t);
        if(s==t)
            cout << "inf" << endl;
        else {
            floyd();
            init();
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if (maz[s][i]!=inf && maz[j][t]!=inf)
                        if (i!=j && mapp[i][j]!=inf && maz[s][i]+mapp[i][j]+maz[j][t]==maz[s][t])   //??????????
                            addedge(i,j,1);    
            printf("%d\n",isap(s, t, n));
        }
    }
    return 0;
}
