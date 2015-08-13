#include<cstdio>
#include<cstring>
using namespace std;
int n;
int a[21],b[21];
int dp[1<<21];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    while(1==scanf("%d",&n))
    {
              memset(dp,-1,sizeof(dp));    
              dp[0]=100;
              n--;
              for(int i=1;i<=n;i++)
               scanf("%d%d",a+i,b+i);
               int fn;
               scanf("%d",&fn);
              for(int i=0;i<(1<<n);i++)
              {
                              for(int j=1;j<=n;j++)
                                      if(!(i&(1<<(j-1))))
                                      {
                                                       int z=i|(1<<(j-1));
                                                       if(dp[i]<a[j])
                                                       continue;
                                                       else
                                                       {
                                                           dp[z]=max(dp[z],dp[i]-a[j]+b[j]);
                                                           if(dp[z]>100)
                                                           dp[z]=100;
                                                       }
                                      }
              }
              int ans=dp[(1<<n)-1]-fn;
              if(ans<0)
              printf("try again\n");
              else
              printf("clear!!!\n");                                                                   
    }
    return 0;
}
