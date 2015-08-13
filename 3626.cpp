#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#define maxn 105
#define inf 1<<30
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct node
{
       int to,l;
};
int n,k,m,v[maxn],dp[110][2200]; 
vector<node>vt[maxn];
void dfs(int x,int fa)
{
     if(vt[x].size()==1&&vt[x][0].to==fa)
                        return;
     for(int i=0;i<vt[x].size();i++)
     {
             int j=vt[x][i].to;
             if(j==fa)
             continue;
             dfs(j,x);
     }
     for(int i=0;i<vt[x].size();i++)
     {
             int j=vt[x][i].to;
             if(j==fa)
             continue;
             int l=2*vt[x][i].l;
             for(int q=m;q>=l;q--)
             for(int w=0;w<=q-l;w++)
             dp[x][q]=max(dp[x][q],dp[x][q-l-w]+dp[j][w]);
     }
}
int main()
{
    while(1==scanf("%d",&n))
    {
                            memset(dp,0,sizeof(dp));
                            for(int i=1;i<=n;i++)
                            vt[i].clear();
                            for(int i=1;i<=n;i++)
                            scanf("%d",v+i);
                            for(int i=1;i<=n-1;i++)
                            {
                                    int a,b,c;
                                    scanf("%d%d%d",&a,&b,&c);
                                    node s;
                                    s.to=b;
                                    s.l=c;
                                    vt[a].push_back(s);
                                    s.to=a;
                                    vt[b].push_back(s);
                            }
                            scanf("%d%d",&k,&m);
                            for(int i=1;i<=n;i++)
                            for(int j=m;j>=0;j--)
                                    dp[i][j]=v[i];
                            dfs(k,0);         
                            printf("%d\n",dp[k][m]);
    }
    return 0;
}
