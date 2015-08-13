#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=99999999; 
struct node
{
       int walk;
       int push;
       friend bool operator<(node a,node b)
       {
              if(a.push!=b.push)
              return a.push<b.push;
              else
              return a.walk<b.walk;
       }
};
struct sta
{
       int people;
       int box;
       node cm;
       friend bool operator<(sta a,sta b)
       {
              return b.cm<a.cm;
       }
};
node dp[500][500]; 
int path[500][500];
int vi[500][500];
char str[30][30];
int n,m;
int dic[4][2]={1,0,0,1,-1,0,0,-1}; 
char ss[8]={'s','e','n','w','S','E','N','W'}; 
int inside(int x,int y)
{
    return  x>=1&&x<=n&&y>=1&&y<=m&&str[x][y]!='#';
}
sta ans; 
void print(sta a,sta b)
{
     sta c=a; 
     if(c.people==b.people&&c.box==b.box)
     return ; 
     int st=a.people,temp;
     int et=a.box,tempp;
     int x1=(st-1)/m+1,y1=(st-1)%m+1,x2=(et-1)/m+1,y2=(et-1)%m+1; 
     int i=path[st][et]; 
     if(i<4)
     {
                        x1-=dic[i][0];
                        y1-=dic[i][1];
                        c.people=(x1-1)*m+y1;
                        print(c,b);
     }
     else
     {
         i-=4;
         
                        x1-=dic[i][0];
                        y1-=dic[i][1];
                        x2-=dic[i][0];
                        y2-=dic[i][1];
                        c.people=(x1-1)*m+y1;
                        c.box=(x2-1)*m+y2;
                        print(c,b);
     }
     printf("%c",ss[path[st][et]]);
}       
int main()
{
    int pro=0;
    while(scanf("%d%d",&n,&m),n+m>0)
    {
                                    memset(path,0,sizeof(path));
                                    memset(str,0,sizeof(str));
                                    for(int i=1;i<=n*m;i++)
                                    for(int j=1;j<=n*m;j++)
                                    {
                                            dp[i][j].walk=INF;
                                            dp[i][j].push=INF;
                                    }
                                    int st,stt,ed;
                                    for(int i=1;i<=n;i++)
                                            scanf("%s",str[i]+1);
                                    for(int i=1;i<=n;i++)
                                    for(int j=1;j<=m;j++)
                                    {
                                            if(str[i][j]=='S')
                                            st=(i-1)*m+j;
                                            if(str[i][j]=='B')
                                            stt=(i-1)*m+j;
                                            if(str[i][j]=='T')
                                            ed=(i-1)*m+j;
                                    }
                                    sta s,start;
                                    s.people=st;
                                    s.box=stt;
                                    s.cm.push=0;
                                    s.cm.walk=0;
                                    start=s; 
                                    priority_queue<sta>q;
                                    q.push(s);
                                    ans.cm.walk=INF;
                                    ans.cm.push=INF; 
                                   dp[st][stt]=s.cm;
                                    while(!q.empty())
                                    {
                                                     sta t; 
                                                     s=q.top();
                                                     if(ans.cm<s.cm)
                                                     break;
                                                     if(s.box==ed)
                                                     {
                                                                  if(s.cm<ans.cm)
                                                                  ans=s;
                                                     } 
                                                     q.pop();
                                                     int x,y; 
                                                     int x1=(s.people-1)/m+1;
                                                     int y1=(s.people-1)%m+1;
                                                     int x2=(s.box-1)/m+1;
                                                     int y2=(s.box-1)%m+1;
                                                     for(int i=0;i<4;i++)
                                                     {
                                                             x=x1+dic[i][0];
                                                             y=y1+dic[i][1];
                                                             t.people=(x-1)*m+y; 
                                                             if(!inside(x,y))
                                                             continue;
                                                             if(x==x2&&y==y2)
                                                             {
                                                                   x+=dic[i][0];
                                                                   y+=dic[i][1];
                                                                   if(!inside(x,y))
                                                                   continue;
                                                                   t.box=(x-1)*m+y;
                                                                   t.cm.walk=s.cm.walk;
                                                                   t.cm.push=s.cm.push+1; 
                                                                   if(t.cm<dp[t.people][t.box])
                                                                   {
                                                                                      dp[t.people][t.box]=t.cm;
                                                                                      path[t.people][t.box]=i+4; 
                                                                                      q.push(t);
                                                                   } 
                                                                          
                                                             } 
                                                             else
                                                             {
                                                                 t.box=s.box;
                                                                 t.cm.walk=s.cm.walk+1;
                                                                 t.cm.push=s.cm.push;
                                                                   if(t.cm<dp[t.people][t.box])
                                                                   {
                                                                                      dp[t.people][t.box]=t.cm;
                                                                                      path[t.people][t.box]=i; 
                                                                                      q.push(t);
                                                                   }  
                                                             } 
                                                     } 
                                    }
                                    printf("Maze #%d\n",++pro);
                                    if(ans.cm.push==INF)
                                    printf("Impossible.\n\n");
                                    else
                                    { print(ans,start);
                                    printf("\n\n");
                                    }
    } 
    return 0;
}
