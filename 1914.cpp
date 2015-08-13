#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int t,s,p;
int x[510],y[510],root[510];
struct node
{
       int x,y;
       double dist;
       friend bool operator<(node a,node b)
       {
              return a.dist<b.dist;
       }
}; 
node q[300000];
double dis(int x,int y)
{
       return sqrt(x*x+y*y);
}
int getroot(int x)
{
    if(x==root[x])
    return x;
    return root[x]=getroot(root[x]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
              int tot=0;
              scanf("%d%d",&s,&p);
              for(int i=1;i<=p;i++)
                      scanf("%d%d",x+i,y+i);
              for(int i=1;i<=p;i++)
              for(int j=i+1;j<=p;j++)
              {
                      node w;
                      w.x=i,w.y=j;
                      w.dist=dis(x[i]-x[j],y[i]-y[j]);
                      q[++tot]=w;
              }
              sort(q+1,q+1+tot);
              for(int i=1;i<=p;i++)
              root[i]=i; 
              double ans[510];
              int cnt=0;
              for(int i=1;i<=tot;i++)
              {
                      int a=q[i].x,b=q[i].y;
                      double d=q[i].dist;
                      a=getroot(a);
                      b=getroot(b);
                      if(a==b)
                      continue;
                      ans[++cnt]=d;
                      root[a]=b;
                      if(cnt==p-1)
                      break;
              }
              cnt-=s;
              printf("%.2f\n",ans[cnt+1]);        
    }
    return 0;
}
