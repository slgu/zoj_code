#include<cstdio>
#include<queue>
using namespace std;
const int MAX=99999999;
int n,m;
int mp[10][10];
int dp[60][60];
struct node
{
       int pe;
       int bo;
       int push;
       friend bool operator<(node a,node b)
       {
              return a.push>b.push;
       }
};
int dic[4][2]={1,0,0,1,-1,0,0,-1};
int in(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]!=1;
}
int main()
{
    while(scanf("%d%d",&m,&n),m!=0||n!=0)
    {
                                         for(int i=1;i<=n;i++)
                                         for(int j=1;j<=m;j++)
                                         scanf("%d",&mp[i][j]);
                                         int people,box,ed;
                                         for(int i=1;i<=n;i++)
                                         for(int j=1;j<=m;j++)
                                         {
                                                 if(mp[i][j]==4)
                                                 people=(i-1)*m+j;
                                                 if(mp[i][j]==2)
                                                 box=(i-1)*m+j;
                                                 if(mp[i][j]==3)
                                                 ed=(i-1)*m+j;
                                         }                          
                                         for(int i=1;i<=50;i++)
                                         for(int j=1;j<=50;j++)
                                           dp[i][j]=MAX;
                                         priority_queue<node>q;
                                         node s,t;
                                         s.pe=people;
                                         s.bo=box;
                                         s.push=0;
                                         int ans=MAX;
                                         q.push(s);
                                         while(!q.empty())
                                         {
                                                       s=q.top();
                                                       q.pop();
                                                       people=s.pe;
                                                       box=s.bo;
                                                       int cnt=s.push;
                                                         int x=(people-1)/m+1;
                                                         int y=(people-1)%m+1;
                                                       if(box==ed)
                                                       {
                                                                  if(ans>cnt)
                                                                  ans=cnt;
                                                                  break; 
                                                       }   
                                                       for(int k=0;k<4;k++)
                                                          {
                                                          int tx=x+dic[k][0];
                                                          int ty=y+dic[k][1];
                                                           int temp=(tx-1)*m+ty;
                                                           if(!in(tx,ty))
                                                           continue;
                                                           if((tx-1)*m+ty==box)
                                                           {
                                                                               tx+=dic[k][0];
                                                                               ty+=dic[k][1];
                                                                               if(!in(tx,ty))
                                                                               continue;
                                                                               t.pe=temp;
                                                                               t.bo=(tx-1)*m+ty;
                                                                               t.push=s.push+1;
                                                                               if(dp[t.pe][t.bo]>t.push)
                                                                               {
                                                                                                        dp[t.pe][t.bo]=t.push;
                                                                                                        q.push(t);
                                                                               }
                                                           }
                                                           else
                                                           {
                                                               t.pe=temp;
                                                               t.bo=box;
                                                               t.push=s.push;
                                                               if(dp[t.pe][t.bo]>t.push)
                                                               {
                                                                                        dp[t.pe][t.bo]=t.push;
                                                                                        q.push(t);
                                                               }
                                                           }
                                                         
                                                   }
                                         }
                                                   if(ans==MAX)
                                                   printf("-1\n");
                                                   else 
                                                   printf("%d\n",ans);
    }
    return 0;
}
