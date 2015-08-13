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

char s[65][65];
int n,m,x[65][65],re[2000],v[2000],r,c;
int dic[4][2]={1,0,-1,0,0,1,0,-1};
vector<int>vt[2000];

int inside(int a,int b)
{
    return a>=1&&a<=r&&b>=1&&b<=c&&s[a][b]=='#';
}

void make()
{
     for(int i=1;i<=r;i++)
     for(int j=1;j<=c;j++)
     {                    
             if(s[i][j]=='.'||(i+j)%2==0)
             continue;
             int a,b;
             for(int k=0;k<4;k++)
             {
                     a=i+dic[k][0];
                     b=j+dic[k][1];
                     if(!inside(a,b))
                     continue;
                     vt[x[i][j]].push_back(x[a][b]);
             }
     }
}

int dfs(int x)
{
    for(int i=0;i<vt[x].size();i++)
    {
            int j=vt[x][i];
            if(!v[j])
            {
                     v[j]=1;
                     if(re[j]==0||dfs(re[j]))
                     {
                                           re[j]=x;
                                           return 1;
                     }
            }
    } 
    return 0;
}
int match()
{
    memset(re,0,sizeof(re));
    for(int i=1;i<=n;i++)
    {
            memset(v,0,sizeof(v));
            if(!dfs(i))
            return 0;
    }
    return 1; 
}

int solve()
{
     make();
     return match();
}
int main()
{
    int pro=0;
    while(scanf("%d%d",&r,&c),r||c)
    {
              n=m=0;
              for(int i=1;i<=1999;i++)
              vt[i].clear();
              for(int i=1;i<=r;i++)
                      scanf("%s",s[i]+1);
              for(int i=1;i<=r;i++)
              for(int j=1;j<=c;j++)
              {
                      if(s[i][j]=='.')
                      continue;
                      if((i+j)%2)
                      x[i][j]=++n;
                      else
                      x[i][j]=++m;
              }
              printf("Case %d: ",++pro);
              if(n!=m)
              {
                      printf("Impossible\n");
                      continue;
              }
              if(solve())
              printf("Possible\n");
              else
              printf("Impossible\n");          
    }
    return 0;
}
