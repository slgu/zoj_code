#include<cstdio>
#include<vector> 
#include<queue> 
#include<cstring> 
using namespace std;
int a[50001],b[50001],c[50001],d[50001],inqueue[50001];
int n,mn,mx;
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
struct node
{
       int id;
       int l;
}; 
vector<node> mp[50001]; 
int main()
{
    while(scanf("%d",&n)==1)
    { 
                            memset(inqueue,0,sizeof(inqueue)); 
                            for(int i=1;i<=50000;i++)
                            mp[i].clear();  
                            for(int i=1;i<=n;i++)
                                    scanf("%d%d%d",&a[i],&b[i],&c[i]);
                            mn=100000; 
                            mx=0;
                            for(int i=1;i<=n;i++)
                            {
                                    mn=min(mn,a[i]);
                                    mx=max(mx,b[i]);
                            }
                            mx++;  
                            for(int i=1;i<=mx;i++)
                                d[i]=9999999; 
                            for(int i=mn+1;i<=mx;i++)
                            {
                                    node s;
                                    s.id=i-1;
                                    s.l=0;
                                    mp[i].push_back(s);
                            }
                            for(int i=mn;i<mx;i++)
                            {
                                    node s;
                                    s.id=i+1;
                                    s.l=1;
                                    mp[i].push_back(s);
                            } 
                            for(int i=1;i<=n;i++)
                            {
                                    node s;
                                    s.id=a[i];
                                    s.l=-c[i];
                                    mp[b[i]+1].push_back(s);
                            }
                            queue<node>q;
                            d[mx]=0;
                            node s;
                            s.id=mx;
                            s.l=0; 
                            q.push(s); 
                            node t; 
                            while(!q.empty())
                            {
                                             s=q.front();
                                             int mi=s.id; 
                                             q.pop(); 
                                             inqueue[mi]=0; 
                                             for(int i=0;i<mp[mi].size();i++)
                                             {
                                                      t.id=mp[mi][i].id;
                                                     int ml=mp[mi][i].l; 
                                                     t.l=d[s.id]+ml; 
                                                     if(t.l<d[t.id])
                                                     {
                                                                    d[t.id]=t.l;
                                                                    if(!inqueue[t.id])
                                                                    {
                                                                                      q.push(t);
                                                                                      inqueue[t.id]=1;
                                                                    } 
                                                     }
                                             }
                            } 
                            printf("%d\n",-d[mn]); 
    } 
    return 0; 
}
