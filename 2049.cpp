#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int a[50000],b[50000],c[50000],d[100010],inqueue[50000];
int n,k,n1;
int mn,mx; 
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int flag=0;
struct node
{
       int id;
       int l;
};
vector<node>vt[23000];
int main()
{
    scanf("%d",&n1);
    while(n1--)
    { 
                            memset(inqueue,0,sizeof(inqueue));
                            for(int i=1;i<=20000;i++)
                            vt[i].clear();
                            flag=0;
                            scanf("%d%d",&k,&n); 
                            mn=100000;
                            mx=-100000; 
                            for(int i=0;i<=100000;i++)
                                    d[i]=-10000000;
                            for(int i=1;i<=n;i++)
                            {
                                     int x,y;
                                    scanf("%d%d",&x,&y);
                                    if(x>y)
                                    {
                                           int temp=x;
                                           x=y;
                                           y=temp;
                                    }
                                    x+=10001;
                                    y+=10001;
                                    mn=min(x,mn);
                                    mx=max(y,mx); 
                                    a[i]=x;
                                    b[i]=y; 
                                    if(y-x+1<k)
                                    c[i]=y-x+1;
                                    else
                                    c[i]=k; 
                            }
                            mx++;
                            for(int i=mn;i<mx;i++)
                            {
                                    node s;
                                    s.id=i+1;
                                    s.l=0;
                                    vt[i].push_back(s);
                            }
                            for(int i=mn+1;i<=mx;i++)
                            {
                                    node s;
                                    s.id=i-1;
                                    s.l=-1;
                                    vt[i].push_back(s);
                            }
                            for(int i=1;i<=n;i++)
                            {
                                    node s;
                                    s.id=b[i]+1;
                                    s.l=c[i];
                                    vt[a[i]].push_back(s);
                            }
                            node s;
                            d[mn]=0;
                            s.id=mn;
                            s.l=0;
                            queue<node>q;
                            q.push(s);
                            inqueue[mn]=1;
                            node t;
                            while(!q.empty())
                            {
                                            s=q.front();
                                            q.pop();
                                            int mi=s.id;
                                            inqueue[mi]=0;
                                            for(int i=0;i<vt[mi].size();i++)
                                            {
                                                      t.id=vt[mi][i].id;
                                                      t.l=vt[mi][i].l+s.l;
                                                      if(t.l>d[t.id])
                                                      {
                                                                   d[t.id]=t.l;
                                                                     if(!inqueue[t.id])
                                                                     q.push(t);
                                                      }
                                            }
                            }
                            printf("%d\n",d[mx]);
                            int flow=0;
                            for(int i=mn+1;i<=mx;i++)
                            {
                                    if(d[i]>flow)
                                    printf("%d\n",i-10002);
                                    flow=d[i];
                            }
                            if(n1!=0)
                            printf("\n");        
    } 
    return 0;
} 
