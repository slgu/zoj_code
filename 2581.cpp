#include<cstdio>
#include<cmath>
const double INF=9999999;
int n;
int x[101];
int y[101];
double dp[101][101];
double dis(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double min(double a,double b)
{
       return a<b?a:b;
} 
int main()
{
    while(1==scanf("%d",&n))
    {
                            for(int i=1;i<=n;i++)
                                    scanf("%d%d",&x[i],&y[i]);
                            for(int i=1;i<=n;i++)
                            for(int j=1;j<=n;j++)
                               dp[i][j]=INF;
                            dp[1][1]=0;
                            for(int i=1;i<=n;i++)
                            for(int j=1;j<=i;j++)
                            {
                                  dp[i+1][j]=min(dp[i+1][j],dp[i][j]+dis(i,i+1));
                                  dp[i+1][i]=min(dp[i+1][i],dp[i][j]+dis(j,i+1));
                            }
                            double ans=INF;
                            for(int j=1;j<n;j++)
                            if(ans>dp[n][j]+dis(j,n))
                              ans=dp[n][j]+dis(j,n);
                             printf("%.2f\n",ans);  
                            
    }
    return 0;
} 
