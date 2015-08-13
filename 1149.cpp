#include<cstdio>
#include<cstring> 
int total;
int sum,j;
int ans[30000];
int dp[120000];
int main()
{
    int pro=0;
    while(1)
    {
            sum=0,j=0;
            for(int i=1;i<=6;i++)
            {
                    scanf("%d",&total);
                    sum+=i*total;
                    int k=1;
                    while(k<total)
                    {
                                  ans[++j]=k*i;
                                  total-=k;
                                  k*=2;
                    }
                    ans[++j]=total*i;
            }
            if(sum==0)
                break;
            printf("Collection #%d:\n",++pro); 
            if(sum%2)
            {
                printf("Can't be divided.\n\n");
                continue;
            }     
            memset(dp,0,sizeof(dp)); 
            dp[0]=1;
            for(int i=1;i<=j;i++)
            for(int k=sum;k>=ans[i];k--)
            {
                    dp[k]=dp[k]||dp[k-ans[i]];
            }
            if(dp[sum/2])
            printf("Can be divided.\n\n");
            else
            printf("Can't be divided.\n\n");  
    }
    return 0;
}
