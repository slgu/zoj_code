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

int n,m,sx,sy,ex,ey;
char g[30][30];
int key[6],vi[30][30],need[6],ff,flag;
int dic[4][2]={1,0,-1,0,0,1,0,-1};

int inside(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m&&g[x][y]!='X';
}

void dfs(int x,int y)
{
     int a,b;
     vi[x][y]=1;
     if(x==ex&&y==ey)
     {
                     flag=1;
                     return;
     }
     for(int i=0;i<4;i++)
     {
             a=x+dic[i][0];
             b=y+dic[i][1];
             if(!inside(a,b))
             continue;
             if(vi[a][b])
             continue;
             if(g[a][b]>='a'&&g[a][b]<='e')
             {
                                           ff=1;
                                           key[g[a][b]-'a'+1]++;
                                           g[a][b]='.';
                                           dfs(a,b);
             }
             if(g[a][b]=='G'||g[a][b]=='.')
             dfs(a,b);
             if(g[a][b]>='A'&&g[a][b]<='E')
             {
                                           int j=g[a][b]-'A'+1;
                                           if(key[j]==need[j])
                                           dfs(a,b);
             }
             if(flag)
             return;
     } 
} 

int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
                                  memset(key,0,sizeof(key)); 
                                  memset(vi,0,sizeof(vi));
                                  memset(need,0,sizeof(need));
                                  for(int i=1;i<=n;i++)
                                          scanf("%s",g[i]+1);
                                  for(int i=1;i<=n;i++)
                                  for(int j=1;j<=m;j++)
                                  {
                                          if(g[i][j]=='S')
                                          {
                                                          sx=i;
                                                          sy=j;
                                          }
                                          if(g[i][j]=='G')
                                          {
                                                          ex=i;
                                                          ey=j;
                                          }
                                          if(g[i][j]>='a'&&g[i][j]<='e')
                                          need[g[i][j]-'a'+1]++;
                                  } 
                                  flag=0;
                                  ff=1;
                                  while(ff)
                                  {
                                          memset(vi,0,sizeof(vi));
                                          ff=0;
                                          dfs(sx,sy);
                                          if(flag)
                                          break;
                                  }
                                  if(flag)
                                  printf("YES\n");
                                  else
                                  printf("NO\n");
    } 
    return 0;
}
