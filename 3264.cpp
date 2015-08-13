#include<cstdio>
#include<cstring> 
int w1[10001],w2[10001],v1[10001],v2[10001],re[10001];
int W,N,dp[50001];
int max(int a,int b)
{
    return a>b?a:b;
} 
void swap(int &a,int &b)
{
     int temp=a;
     a=b;
     b=temp;
} 
int main()
{
    while(scanf("%d%d",&W,&N)!=EOF)
    {
                                   memset(dp,0,sizeof(dp)); 
                                   W/=100;
                                   for(int i=1;i<=N;i++)
                                   { 
                                           scanf("%d%d%d%d%d",w1+i,v1+i,w2+i,v2+i,re+i);
                                           w1[i]/=100;w2[i]/=100; 
                                           if(re[i]==2&&w1[i]>w2[i])
                                           {
                                                                    swap(w1[i],w2[i]);
                                                                    swap(v1[i],v2[i]);
                                           }
                                   } 
                                   for(int i=1;i<=N;i++)
                                   {  
                                           if(re[i]==1) 
                                           {
                                                        for(int j=W;j>=w1[i]+w2[i];j--)
                                                        dp[j]=max(dp[j-w1[i]-w2[i]]+v1[i]+v2[i],dp[j]);
                                           }
                                           if(re[i]==2)
                                           {
                                                       for(int j=W;j>=w2[i];j--) 
                                                               dp[j]=max(dp[j],max(dp[j-w1[i]]+v1[i],dp[j-w2[i]]+v2[i]));
                                                       for(int j=w2[i]-1;j>=w1[i];j--)
                                                               dp[j]=max(dp[j],dp[j-w1[i]]+v1[i]); 
                                           } 
                                           if(re[i]==3)
                                           {
                                                       for(int j=W;j>=w1[i]+w2[i];j--)
                                                        dp[j]=max(max(dp[j-w1[i]-w2[i]]+v1[i]+v2[i],dp[j-w1[i]]+v1[i]),dp[j]);
                                                       for(int j=w1[i]+w2[i]-1;j>=w1[i];j--)
                                                       dp[j]=max(dp[j],dp[j-w1[i]]+v1[i]);
                                           }
                                   }
                                          printf("%d\n",dp[W]);
    }
    return 0;
} 

