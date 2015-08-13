#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=999999;
int flow[104][104];
int cap[104][104];
int p[104];
int a[104];
int min(int a,int b)
{
    return a<b?a:b;
} 
int main()
{
    int n,np,nc,m,f;
    char c;
    while(cin>>n>>np>>nc>>m)
    {
     memset(cap,0,sizeof(cap));
        for(int i=1;i<=m;i++)
        {                        
             int a,b,maxn;
             while((c=getchar())!='(');
             scanf("%d",&a);
             getchar();
             scanf("%d",&b);
             getchar();
             scanf("%d",&maxn);
             a++;
             b++;
             if(a!=b)
             cap[a][b]=maxn;
        }
        for(int i=1;i<=np;i++)
        {       
               while((c=getchar())!='(');
               int a,maxn;
               scanf("%d",&a);
               getchar();
               scanf("%d",&maxn);
               a++;
               cap[0][a]=maxn;
        }
        for(int i=1;i<=nc;i++)
        {
                while((c=getchar())!='(');
                int a,maxn;
                scanf("%d",&a);
                getchar();
                scanf("%d",&maxn);
                a++;
                cap[a][n+1]=maxn;
        } 
        memset(flow,0,sizeof(flow));
        queue <int> q;
        f=0;
        for(;;)
        {
            q.push(0);
            memset(a,0,sizeof(a));
            a[0]=MAX;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int i=1;i<=n+1;i++)
                if(!a[i]&&cap[u][i]>flow[u][i])
                {
                       p[i]=u;
                       q.push(i);
                       a[i]=min(a[u],cap[u][i]-flow[u][i]);
                }
            }
            if(a[n+1]==0)
            {
                 break;
            }
            for(int u=n+1;u!=0;u=p[u])
            {
                    flow[p[u]][u]+=a[n+1];
                    flow[u][p[u]]-=a[n+1];
           }
            f+=a[n+1];
         }
         cout<<f<<endl;
    }
    return 0;
} 
