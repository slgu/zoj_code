#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n,m,q;
map<int,int>mp;
vector<int>vt[30001]; 
struct node
{
       int id;
       int s;
       int h;
       friend bool operator<(node a,node b)
       {
              return a.s<b.s;
       } 
};
node pe[30001];
int nxt[30001];
int dfs(int x)
{
    int sum=1;
    for(int i=0;i<vt[x].size();i++)
    {
                               sum+=dfs(vt[x][i]);
    }
    return sum;
} 
int main()
{
    scanf("%d",&n);
    while(n--)
    {
              mp.clear();
              memset(nxt,0,sizeof(nxt));
              scanf("%d%d",&m,&q);
              for(int i=1;i<=m;i++)
              vt[i].clear();
              for(int i=1;i<=m;i++)
                      scanf("%d%d%d",&pe[i].id,&pe[i].s,&pe[i].h);
              sort(pe+1,pe+m+1);
              for(int i=1;i<=m;i++)
              mp[pe[i].id]=i;
              for(int a=1;a<=m;a++)
              {
                      int height=pe[a].h;
                      int j;
                      for(j=a+1;j<=m;j++)
                      if(pe[j].h>=height)
                      break;
                      if(j>m)
                      nxt[a]=0;
                      else
                      {
                       nxt[a]=j;
                       vt[j].push_back(a);
                       }
                                          
              }
              for(int i=1;i<=q;i++)
              {
                      int a,k;
                      scanf("%d",&a);
                      k=mp[a];
                      int ans=nxt[k];
                      if(ans==0)
                      printf("0 ");
                      else
                      printf("%d ",pe[ans].id);
                      ans=dfs(k);
                      ans--;
                      printf("%d\n",ans);
              }
    }
    return 0;
} 
