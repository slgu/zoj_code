#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int t,n;
int p[11][11];
int dp[1<<10];
string s[1<<10];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
              memset(dp,-1,sizeof(dp));
              scanf("%d",&n);
              for(int i=1;i<=n;i++)
              for(int j=1;j<=n;j++)
                      scanf("%d",&p[i][j]);
              dp[0]=0;
              s[0]="";
              for(int i=0;i<(1<<n);i++)
              {
                      for(int j=1;j<=n;j++)
                      {
                              if((i&(1<<(j-1))))
                              continue;
                              int z=i|(1<<(j-1));
                              int mx=p[j][j];
                              for(int k=1;k<=n;k++)
                              {
                                      if(z&(1<<(k-1)))
                                      {
                                                      mx=max(mx,p[k][j]);
                                      }
                              }
                              if(dp[z]<dp[i]+mx)
                              {
                                                dp[z]=dp[i]+mx;
                                                s[z]=s[i]+(char)('A'+j-1);
                              }
                              else
                              if(dp[z]==dp[i]+mx)
                              {
                                                 string ss=s[i]+(char)('A'+j-1);
                                                 if(s[z]>ss)
                                                 s[z]=ss;
                              }
                                                 
                      }
              }
              printf("%.2lf\n%s\n",(double)dp[(1<<n)-1]/100,s[(1<<n)-1].c_str());
    }
    return 0;
}
