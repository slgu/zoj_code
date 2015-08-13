#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
using namespace std;
struct mice
{
       int id;
       int x;
       int y;
       friend int operator<(mice a,mice b)
       {
              if(a.x==b.x)
              return a.y>b.y;
              return a.x<b.x;
       }
} t[1010];
int p[1010];
int dp[1010];
int ans[1010];
int  main()
{
     int n=1,max,index;
     while(scanf("%d %d",&t[n].x,&t[n].y)!=EOF)
     {
                                          t[n].id=n;
                                          n++;
     }
     n--;
     sort(t+1,t+1+n); 
     dp[1]=1;
     p[1]=0;
     for(int i=2;i<=n;i++)
     {
             max=0;
             for(int j=1;j<=i;j++)
             if(t[j].x!=t[i].x&&t[j].y>t[i].y)
             {
                                              if(dp[j]>max)
                                              {
                                                           max=dp[j];
                                                           index=j;
                                              }
             }
             if(max==0)
             {
                       p[i]=0;
                       dp[i]=1;
             }
             else
             {
                 dp[i]=max+1;
                 p[i]=index;
             }
     }
     max=0;
     for(int i=1;i<=n;i++)
             if(dp[i]>max)
             {
                          max=dp[i];
                          index=i;
             }
     int j=0;
     while(index!=0)
     {
              ans[++j]=t[index].id;    
              index=p[index];
     }  
          cout<<j<<endl;
        for(int  i=j;i>=1;i--)
             cout<<ans[i]<<endl;
     return 0;
}
