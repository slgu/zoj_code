#include<cstdio>
#include<cstring>
int n,k;
int d[201];
int map[201][201];
int dp[201][31]; 
const int INF=9999999;
#define abs(x)  x>0?x:-x
#define min(a,b) a<b?a:b;
int main()
{
    int cnt=0;
    while(scanf("%d%d",&n,&k),n!=0||k!=0)
    { 
                      memset(map,-1,sizeof(map));
                    for(int i=1;i<=n;i++)
                            scanf("%d",&d[i]);
                    for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                    {
                            int m=(i+j)/2;
                            int sum=0;
                            for(int w=i;w<=j;w++)
                            sum+=abs((d[w]-d[m]));
                            map[i][j]=sum;
                    }
                    for(int i=1;i<=n;i++)
                    dp[i][1]=map[1][i];
                    for(int i=1;i<=n;i++)
                    for(int j=2;j<=k;j++)
                    {
                            int ans=INF;
                            for(int w=1;w<i;w++)
                            ans=min(ans,dp[w][j-1]+map[w+1][i]);
                            dp[i][j]=ans;
                    }
                    printf("Chain %d\n",++cnt);
                    printf("Total distance sum = %d\n\n",dp[n][k]); 
    }
    return 0;
} 
