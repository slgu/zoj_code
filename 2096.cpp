#include<cstdio>
#define INF 9999999;
int n;
int t[101];
int dp[101][101];
int min(int a,int b)
{
    return a<b?a:b;
}
int abs(int a)
{
    return a>0?a:-a;
}
int main()
{
    while(scanf("%d",&n),n)
    {
                           for(int i=0;i<=n;i++)
                           for(int j=0;j<=n;j++)
                           dp[i][j]=INF;
                           for(int i=1;i<=n;i++)
                           {
                                   scanf("%d",t+n-i+1);
                           } 
                           dp[1][1]=0; 
                           for(int i=1;i<=n;i++)
                           for(int j=1;j<=i;j++)
                           {
                                   dp[i+1][i]=min(dp[i+1][i],dp[i][j]+abs(t[j]-t[i+1]));
                                   dp[i+1][j]=min(dp[i+1][j],dp[i][j]+abs(t[i+1]-t[i]));
                           }
                           int ans=INF; 
                           
                           /*for(int i=1;i<=n;i++)
                           for(int j=1;j<=i;j++)
                           {
                                   printf("%d %d %d\n",i,j,dp[i][j]);
                           } */ 
                           for(int i=1;i<n;i++)
                           {
                                   ans=min(ans,dp[n][i]); 
                           } 
                           printf("%d\n",ans); 
    } 
    return 0;
}
