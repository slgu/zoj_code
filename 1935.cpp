#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MIN=-999999999;
int e[110],mp[110][110];
int n;
int dis[110],inqueue[110],count[110];
void spfa()
{
      memset(inqueue,0,sizeof(inqueue));
      memset(count,0,sizeof(count));
     queue<int>q;
     q.push(1);
     inqueue[1]=1;
     count[1]++;
     while(!q.empty())
     {
                      int c=q.front();
                      if(count[c]>n)
                      break;
                      q.pop();
                      inqueue[c]=0;
                      for(int j=1;j<=n;j++)
                      {
                              if(!mp[c][j])
                              continue;
                              if(dis[j]<dis[c]+e[j])
                              {
                                                    dis[j]=dis[c]+e[j];
                                                    if(!inqueue[j])
                                                    {
                                                                   q.push(j);
                                                                   count[j]++;
                                                                   inqueue[j]=1;
                                                    }
                              }
                      }
     }
}                                               
int main()
{
    while(scanf("%d",&n),n!=-1)
    {
               memset(mp,0,sizeof(mp));
               memset(dis,0,sizeof(dis));
               for(int i=1;i<=n;i++)
               {
                       int a,b,c;
                       scanf("%d%d",&a,&b);
                       e[i]=a;
                       for(int j=1;j<=b;j++)
                       {
                               scanf("%d",&c);
                               mp[i][c]=1;
                       }
               }
               dis[1]=100; 
               spfa();
              int ff=1;
   while(ff)//传递闭包
   {
    ff=0;
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
     {
      if(mp[i][j])
      {
       for(int k=1;k<=n;k++)
       {
        if(mp[j][k]&&!mp[i][k])
        {
         ff=1;
         mp[i][k]=true;
        }
       }
      }
     }
    }
   }

               if(dis[n]>0)
                          printf("winnable\n");
               else
               {
                   int flag=0;
                   for(int i=1;i<=n;i++)
                   {
                    if(count[i]>n&&mp[i][n])
                    {
                          flag=1;
                          printf("winnable\n");
                          
                          break;
                    }
                   }
                   if(!flag)
                             printf("hopeless\n");
               }
    }
    return 0;
}    
