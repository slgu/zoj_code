#include<cstdio>
#include<map>
using namespace std;
int n,m;
map<int ,int>fa;
map<int ,int >mp;
int getroot(int x)
{
    if(fa[x]==x)
    return x;
    else
    return fa[x]=getroot(fa[x]);
}    
int main()
{
    int pro=0;
    while(scanf("%d%d",&m,&n),n!=-1||m!=-1)
    {            
                 if(m==0&&n==0)
                 {
                                       printf("Case %d is a tree.\n",++pro);
                         continue;
                 }
                 int flag=1,count=0; 
                 mp.clear();
                 fa.clear();
                 while(1)
                 {
                         if(m==0&&n==0)
                         break;
                         count++;
                         if(n==m)
                                 flag=0;
                         if(mp.find(m)!=mp.end())
                         {
                                     if(mp.find(n)==mp.end())
                                     {
                                                             m=getroot(m);
                                                             fa[n]=m;
                                                             mp[n]=1;
                                     }
                                     else
                                     {
                                                             int k=getroot(n);
                                                             if(k!=n)
                                                             {
                                                                     flag=0;
                                                             }
                                                             else
                                                             {
                                                                 int c=getroot(m);
                                                                 if(c==n)
                                                                         flag=0;
                                                                 else
                                                                     fa[n]=m;
                                                             }
                                     }                           
                         }
                         else
                         {
                             mp[m]=1;
                             fa[m]=m;
                             if(mp.find(n)==mp.end())
                             {
                                                   fa[n]=m;
                                                   mp[n]=1;
                             }
                             else
                             {
                                 int k=getroot(n);
                                 if(k!=n)
                                 {
                                         flag=0;
                                 }
                                 else
                                 {
                                         fa[n]=m;
                                 }
                             }
                         }
                         scanf("%d%d",&m,&n);
                 }
                         //printf("%d %d\n\n",mp.size(),count);
                         if(flag==0||mp.size()!=count+1)
                         printf("Case %d is not a tree.\n",++pro);
                         else
                         printf("Case %d is a tree.\n",++pro);
                   
    }
    return 0;
}

