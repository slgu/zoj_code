#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
int map[30][30],appear[30];
int n,m,j,sum;
bool de,co;
string ans;
void toposort()
{
     queue<int>q;
     ans="";
     int size[30],flag=false,dn=0,cnt=0;
     memset(size,0,sizeof(size));
     for(int i=1;i<=n;i++)
     {
             if(!appear[i])
                           continue;
             for(int j=1;j<=n;j++)
             if(map[j][i])
             size[i]++;
             if(!size[i])
             {
                         q.push(i);
             }
     }
     if(q.empty())
              co=true;    
     if(q.size()>1)
                   flag=true;
     while(!q.empty())
     {
                      int s=q.front();
                      q.pop();
                      ans+=char(s+'A'-1); 
                      dn++;
                      for(int i=1;i<=n;i++)
                      if(map[s][i])
                      {
                                   size[i]--;
                                   if(size[i]==0)
                                   q.push(i);
                      }
                      if(q.size()>1)
                      flag=true;
     }
     for(int i=1;i<=n;i++)
     if(appear[i])cnt++;
     if(cnt==dn&&!flag&&cnt==n)
                               de=true;
     if(cnt>dn)
               co=true;
} 
int main()
{
    char a[3];
    while(scanf("%d%d",&n,&m),!(m==0&&n==0))
    {
                                 sum=0;
                                 int count=0;
                                 de=co=false;
                                 memset(map,0,sizeof(map));
                                 memset(appear,0,sizeof(appear));
                                 for(int i=1;i<=m;i++)
                                 {
                                       int x,y;
                                       scanf("%s",a);
                                       if(de||co)continue; 
                                       x=*a-'A'+1;
                                       y=*(a+2)-'A'+1;
                                       map[x][y]=1;
                                       appear[x]=appear[y]=1;
                                       toposort();
                                       if(de||co)
                                       count=i;
                                 }
                                       if(de)
                                       {
                                             cout<<"Sorted sequence determined after "<<count<<" relations: "<<ans<<"."<<endl;
                                             
                                       }
                                       else
                                           if(co)
                                             cout<<"Inconsistency found after "<<count<<" relations."<<endl;
                                       else
                                           cout<<"Sorted sequence cannot be determined."<<endl;
                                   
    }
    return 0;
} 
