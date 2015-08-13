#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
int dp[110][110];
int n;
int main()
{
    while(scanf("%d",&n),n)
    {
                           memset(dp,0,sizeof(dp));
                           for(int i=1;i<=n;i++)
                           {
                                   int a;
                                   scanf("%d",&a);
                                   for(int j=1;j<=a;j++)
                                   {
                                           int b,c;
                                           scanf("%d%d",&b,&c);
                                           dp[i][b]=c;
                                   }
                           }
                           for(int k=1;k<=n;k++)
                           for(int i=1;i<=n;i++)
                           for(int j=1;j<=n;j++)
                           {
                                   if(i==j||i==k||j==k)
                                   continue;
                                   if(dp[i][k]&&dp[k][j])
                                   {
                                                         if(dp[i][j]==0||dp[i][j]>dp[i][k]+dp[k][j])
                                                         dp[i][j]=dp[i][k]+dp[k][j];
                                   }
                           }
                           int mx=99999999;
                           int index;
                           for(int i=1;i<=n;i++)
                           {
                            int cost=0,mm=0; 
                            for(int j=1;j<=n;j++)
                           if(dp[i][j])
                           {
                                       cost++;
                                       mm=max(mm,dp[i][j]);
                           }
                           if(cost==n-1)
                           {
                                        if(mx>mm)
                                        {
                                                 mx=mm;
                                                 index=i;
                                        }
                           }
                           }
                           if(mx==99999999)
                           printf("disjoint\n");
                           else
                           printf("%d %d\n",index,mx);
    }
    return 0;
}
