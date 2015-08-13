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

int k,a[15],vi[15];
void dfs(int i,int x)
{
     if(x==6)
     {
             int flag=0;
             for(int i=1;i<=k;i++)
             if(vi[i])
             {
                      if(flag)printf(" %d",a[i]);
                      else
                      {
                          flag=1;
                          printf("%d",a[i]);
                      }
             }
             puts("");
             return;
     }
     if(x>6)
     return;
     if(i>k)
     return;
     vi[i]=1;
     dfs(i+1,x+1);
     vi[i]=0;
     dfs(i+1,x);
}
int main()
{
    int t=0;
    while(scanf("%d",&k),k)
    {
                           if(!t)
                           t=1;
                           else
                           printf("\n");
                           memset(vi,0,sizeof(vi));
                          for(int i=1;i<=k;i++)
                          scanf("%d",a+i);
                          dfs(1,0); 
    } 
    return 0;
}
