#include<cstdio>
#include<cstring> 
int dp[101][2001],n; 
int max(int a,int b)
{
    return a>b?a:b;
} 
int main()
{
    while(scanf("%d",&n),n>=0)
    {
                              memset(dp,-1,sizeof(dp));
                              dp[0][0]=0; 
                              for(int i=1;i<=n;i++)
                              {
                                      int c; 
                                      scanf("%d",&c); 
                                      for(int j=2000;j>=0;j--)
                                      {
                                              dp[i][j]=dp[i-1][j];
                                              if(j>c&&dp[i-1][j-c]!=-1) 
                                              dp[i][j]=max(dp[i][j],dp[i-1][j-c]+c);
                                              if(c>=j&&dp[i-1][c-j]!=-1) 
                                              dp[i][j]=max(dp[i][j],dp[i-1][c-j]+j);
                                              if(dp[i-1][j+c]!=-1) 
                                              dp[i][j]=max(dp[i-1][j+c],dp[i][j]); 
                                      }
                              }
                              if(dp[n][0]>0) 
                              printf("%d\n",dp[n][0]);
                              else
                              printf("Sorry\n");
    }
    return 0;
} 
