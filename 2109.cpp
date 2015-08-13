#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
       int j,f;
       friend bool operator<(node a,node b)
       {
              return a.j*b.f>a.f*b.j;
       }
};
node a[1000];
int m,n;
int main()
{
    while(scanf("%d%d",&m,&n),n!=-1||m!=-1)
    {
                                  for(int i=1;i<=n;i++)
                                          scanf("%d%d",&a[i].j,&a[i].f);
                                  sort(a+1,a+1+n);
                                  double ans=0;
                                  for(int i=1;i<=n;i++)
                                  {
                                          if(m>a[i].f)
                                          {
                                                      m-=a[i].f;
                                                      ans+=a[i].j;
                                          }
                                          else
                                              if(m<=a[i].f)
                                          {
                                                       ans+=1.0*m*a[i].j/a[i].f;
                                                       break;
                                          }
                                  }        
                                  printf("%.3f\n",ans);      
    }
    return 0;
}
