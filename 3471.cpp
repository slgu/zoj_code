#include<cstdio>
#include<cstring>
int n;
int max(int a,int b)
{
    return a>b?a:b;
}
int re[11][11];
int dp[1<<10];
int main()
{
    while(scanf("%d",&n),n)
    {
               memset(dp,0,sizeof(dp));
               for(int i=1;i<=n;i++)
               for(int j=1;j<=n;j++)
               scanf("%d",&re[i][j]);
               for(int i=0;i<(1<<n);i++)
               {
                       for(int j=1;j<=n;j++)
                       {
                               if(i&(1<<(j-1)))
                               continue;
                               int z=i|(1<<(j-1));
                               for(int k=1;k<=n;k++)
                               {
                                       if((1<<(k-1))&z)
                                       continue;
                                       dp[z]=max(dp[z],dp[i]+re[k][j]);
                               }
                       }
               }
               int ans=0;
               for(int i=0;i<(1<<n);i++)
               ans=max(ans,dp[i]);
               printf("%d\n",ans);
    }
    return 0;
} 
