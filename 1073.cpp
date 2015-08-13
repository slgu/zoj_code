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

int v[100],l,t[100];
char num[100];

void mul(int x)
{
     int sum[100],jinwei=0;
     for(int i=l;i>=1;i--)
     {
             int temp=v[i]*x+jinwei;
             sum[i]=temp%10;
             jinwei=temp/10;
     }
     for(int i=1;i<=l;i++)
     t[i]=sum[i];
}
int gao()
{
    for(int i=1;i<=l;i++)
    {
            if(v[1]==t[i])
            {
                          int k=i,j=1;
                          for(j=1;j<=l;j++)
                          {
                                            int q=j+k-1;
                                            if(q==l)
                                            ;
                                            else
                                            q=q%l;
                                            if(v[j]!=t[q])
                                            break;
                          }
                          if(j>l)
                          return 1;
            }
    }
    return 0;
}
void solve()
{
     for(int i=2;i<=l;i++)
     {
             mul(i);
            /* for(int i=1;i<=l;i++)
             printf("%d",t[i]);
             puts("");*/
             if(!gao())
             {
                       printf("%s is not cyclic\n",num+1);
                       return;
             }
     }
     printf("%s is cyclic\n",num+1);
}
int main()
{
    while(scanf("%s",num+1)!=EOF)
    {
                       l=strlen(num+1);
                       for(int i=1;i<=l;i++)
                       v[i]=num[i]-'0';
                       solve(); 
                       getchar();                                    
    } 
    return 0;
}
