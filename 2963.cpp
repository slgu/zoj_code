#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct node
{
       int id;
       int l;
       friend bool operator<(node a,node b)
       {
              return a.l>b.l;
       } 
};
const int MAX=99999999; 
vector<node>vt[501];
int cost[501];
int mark[501];
int vi[501][501];
int pa[501][501],psp[501][501];
int temp[501]; 
int n;
int dp[140000][20];
int maxn(int a,int b)
{
    return a<b?a:b;
} 
void dij(int x)
{
     priority_queue<node>q;
     pa[x][x]=cost[x];
     node s;
     s.id=x;
     s.l=0;
     node tt;
     q.push(s);
     int count=0;
     while(!q.empty()&&count<n)
     {
                      s=q.top();
                      q.pop();
                      int mi=s.id;
                      if(vi[x][mi])
                      continue;
                      vi[x][mi]=1;
                      count++;
                      for(int i=0;i<vt[mi].size();i++)
                      {
                              int t=vt[mi][i].id;
                              int le=vt[mi][i].l;
                              if(!vi[x][t]&&pa[x][t]>pa[x][mi]+le+cost[t])
                              {
                                                                          pa[x][t]=pa[x][mi]+le+cost[t];
                                                                          tt.id=t;
                                                                          tt.l=pa[x][t];
                                                                          q.push(tt);
                              }
                      }
     }
}                               
int main()
{
    while(1==scanf("%d",&n))
    {
                            memset(dp,-1,sizeof(dp)); 
                            for(int i=1;i<=n;i++)
                            {
                                    temp[i]=0; 
                                    vt[i].clear(); 
                            for(int j=1;j<=n;j++) 
                            {
                                    pa[i][j]=MAX;
                                    vi[i][j]=0;
                            } 
                            } 
                            for(int i=1;i<=n;i++)
                                    scanf("%d",cost+i);
                            int t;
                            scanf("%d",&t);
                            for(int i=1;i<=t;i++)
                            {
                                    int a;
                                    scanf("%d",&a);
                                    temp[a]=1;
                            } 
                            int m;
                            scanf("%d",&m);
                            for(int i=1;i<=m;i++)
                            {
                                    int a,b,c;
                                    scanf("%d%d%d",&a,&b,&c);
                                    node s;
                                    s.id=b;
                                    s.l=c;
                                    vt[a].push_back(s);
                                    s.id=a;
                                    vt[b].push_back(s);
                            }
                            int st,ed;
                            scanf("%d%d",&st,&ed);
                            int jj=0; 
                            mark[++jj]=st;
                            for(int i=1;i<=n;i++)
                            {
                                    if(i!=st&&i!=ed&&temp[i])
                                    mark[++jj]=i;
                            } 
                            if(st!=ed)
                            mark[++jj]=ed;
                            for(int i=1;i<=jj;i++)
                                    dij(mark[i]);
                            for(int i=1;i<=jj;i++)
                                    for(int j=1;j<=jj;j++)
                                            psp[i][j]=pa[mark[i]][mark[j]];
                            if(t==0||jj==1)
                            {
                                           printf("%d\n",pa[st][ed]);
                                           continue;
                            }
                      /*      printf("%d\n",jj);
                            for(int i=1;i<=jj;i++)
                            for(int j=1;j<=jj;j++)
                            printf("%d %d %d\n",i,j,psp[i][j]);*/
                            dp[1][1]=psp[1][1];
                            for(int i=1;i<(1<<jj);i++)
                            for(int j=1;j<=jj;j++)
                            {
                                    if(dp[i][j]==-1)
                                    continue;
                                    for(int k=1;k<=jj;k++)
                                    if(!(i&(1<<(k-1))))
                                    {
                                                       int z=i|(1<<(k-1));
                                                       if(dp[z][k]==-1||dp[i][j]+psp[j][k]-cost[mark[j]]<dp[z][k])
                                                       dp[z][k]=dp[i][j]+psp[j][k]-cost[mark[j]];
                                    }
                            }
                            if(st!=ed)
                            printf("%d\n",dp[(1<<jj)-1][jj]);
                            else
                            {
                                int w=((1<<jj)-1);
                                int ans=MAX;
                                for(int i=2;i<=jj;i++)
                                {
                                        ans=maxn(ans,dp[w][i]+psp[i][1]-cost[mark[i]]);
                                }
                                printf("%d\n",ans);
                            }
    }
    return 0;
}
                                
