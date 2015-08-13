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

int n;
ll p2[40],p3[30],p7[20],p5[30];
ll ans[6000];
int main()
{
    p2[0]=1,p3[0]=p7[0]=p5[0]=1;
    int a,b,c,d;
    for(a=1;a<=40;a++)
    {
                      p2[a]=p2[a-1]*2;
                      if(p2[a]>2000000000)
                      break;
    } 
    for(b=1;b<=30;b++)
    {
                      p3[b]=p3[b-1]*3;
                      if(p3[b]>2000000000)
                      break;
    }
    for(c=1;c<=20;c++)
    {
                      p7[c]=p7[c-1]*7;
                      if(p7[c]>2000000000)
                      break;
    }
    for(d=1;d<=30;d++)
    {
                      p5[d]=p5[d-1]*5;
                      if(p5[d]>2000000000)
                      break;
    }
    int cnt=0;
                    for(int i=0;i<a;i++)
                    for(int j=0;j<b;j++)
                    {
                            if(p2[i]*p3[j]>2000000000)
                            break;
                            for(int k=0;k<c;k++)
                            {
                                    if(p2[i]*p3[j]*p7[k]>2000000000)
                                    break;
                                    for(int w=0;w<d;w++)
                                    {
                                            if(p2[i]*p3[j]*p7[k]*p5[w]>2000000000)
                                            break;
                                            ans[++cnt]=p2[i]*p3[j]*p7[k]*p5[w];
                                    }
                            }
                    }
                    sort(ans+1,ans+cnt+1);
    while(scanf("%d",&n),n)
    {
                           printf("The %d",n);
                           int ten=n/10%10;
                           if(n%10==1&&ten!=1)
                           printf("st");
                           else
                           if(n%10==2&&ten!=1)
                           printf("nd");
                           else
                           if(n%10==3&&ten!=1)
                           printf("rd");
                           else
                           printf("th");
                           printf(" humble number is %d.\n",ans[n]);
    }
    return 0;
}
