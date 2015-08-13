#include<cstdio>
#include<vector>
using namespace std; 
int d[120]; 
int n,m; 
vector<int>vt[101]; 
struct EDGE
{
        int x,y;
        int le;
}edge[101];
int  bellford()
{
      for(int i=1;i<=n;i++)
      for(int i=1;i<=m;i++)
      {
              int a=edge[i].x;
              int b=edge[i].y;
              int l=edge[i].le;
              if(d[b]+l>d[a])
              d[a]=d[b]+l;
      }
      for(int i=1;i<=m;i++)
      {
              int a=edge[i].x;
              int b=edge[i].y;
              int l=edge[i].le;
              if(d[b]+l>d[a])
              return 1;
      }
      return 0;
} 
int main()
{
    while(scanf("%d%d",&n,&m),n>0)
    {
                                  for(int i=0;i<=100;i++)
                                  d[i]=0;  
                                  for(int i=1;i<=m;i++) 
                                  {
                                          int si,ni,ki;
                                          char oi[3];
                                          scanf("%d%d%s%d",&si,&ni,oi,&ki); 
                                          if(*oi=='l') 
                                          {             edge[i].x=si-1;
                                                        edge[i].y=si+ni;
                                                        edge[i].le=1-ki;
                                          } 
                                          else
                                          {
                                              edge[i].x=si+ni;
                                              edge[i].y=si-1;
                                              edge[i].le=ki+1;
                                          } 
                                            
                                  }
                                  if(bellford())
                                  printf("successful conspiracy\n");
                                  else
                                  printf("lamentable kingdom\n"); 
    }
    return 0; 
} 
