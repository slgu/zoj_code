#include<cstdio>
#include<cstring>
int m,n;
int tobuy[102];
struct node
{
       int id;
       double p;
} sup[100001];
double dp[101];
double min(double a,double b)
{
    return a<b?a:b;
}
int main()
{
    while(scanf("%d%d",&m,&n),m+n>0)
    {
                                    for(int i=0;i<=m;i++)
                                    dp[i]=-1;
                                    dp[0]=0;
                                    for(int i=1;i<=m;i++)
                                    scanf("%d",&tobuy[i]);
                                    for(int i=1;i<=n;i++)
                                    {
                                            scanf("%d%lf",&sup[i].id,&sup[i].p);
                                            for(int j=m;j>=1;j--)
                                            if(tobuy[j]==sup[i].id)
                                            {
                                                    if(dp[j]==-1&&dp[j-1]!=-1)
                                                         dp[j]=dp[j-1]+sup[i].p;
                                                    if(dp[j]!=-1&&dp[j-1]!=-1)
                                                       dp[j]=min(dp[j],dp[j-1]+sup[i].p);
                                            }
                                    }
                                     if(dp[m]==-1.0)
                                     printf("Impossible\n");
                                     else
                                     printf("%.2f\n",dp[m]);                           
    }
    return 0;
}
