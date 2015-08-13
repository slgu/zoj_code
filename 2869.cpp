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

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int t,n,a,b,k,r[10],vi[10]; 
vector<int>vt[10001][15];

int dfs(int in,int x)
{
    for(int i=0;i<vt[in][x].size();i++)
    {
            int j=vt[in][x][i];
            if(!vi[j])
            {
                      vi[j]=1;
                      if(r[j]==-1||dfs(in,r[j]))
                      {
                                             r[j]=x;
                                             return 1;
                      }
            }
    }
    return 0;
}

int gao(int x)
{
    memset(r,-1,sizeof(r));
    for(int i=1;i<=n;i++)
    {
            memset(vi,0,sizeof(vi));
            if(vt[x][i].size()==0)
            continue;
            if(!dfs(x,i))
            return 1;
    }
    return 0;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    { 
            scanf("%d",&n);  
            for(int i=1;i<=10000;i++)
            for(int j=1;j<=15;j++)
            vt[i][j].clear();
            for(int i=1;i<=n;i++)
            {
                    scanf("%d%d%d",&a,&b,&k);
                    for(int j=1;j<=k;j++)
                    {
                            int c;
                            scanf("%d",&c);
                            for(int z=a;z<=b;z++)
                            vt[z][i].push_back(c);
                    }
            }
            int i;
            for(i=1;i<=10000;i++)
                    if(gao(i))break; 
            if(i>10000)
            printf("YES\n");
            else
            printf("NO\n");
    } 
    return 0;
}
