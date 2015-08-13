#include<cstdio>
#include<cstring>
int t,n,jishu[120];
int vi[120],chaojiflag;
void dfs(int i,int sum)
{
     if(i<=0)
     return;
    if(!jishu[i])
    {
                 dfs(i-1,sum);
                 return;
    }
    if(vi[i]>=jishu[i])
    {
                       dfs(i-1,sum);
                       return;
    }
    vi[i]++;
    if(sum+i==t)
    {
                   chaojiflag=1;
                   int flag=1;
                   for(int j=100;j>=1;j--)
                   {
                           if(!vi[j])
                           continue;
                           for(int k=1;k<=vi[j];k++)
                           if(flag)
                                   {
                                           printf("%d",j);
                                           flag=0;
                                   }
                                   else
                                   {
                                       flag=0;
                                       printf("+%d",j);
                                   }
                           
                   }
                   puts("");
    }
    else
        if(sum+i>t);
    else        
        dfs(i,sum+i);
    vi[i]--;
    dfs(i-1,sum);
}
int main()                       
{
    while(scanf("%d%d",&t,&n),n)
    {
                                   chaojiflag=0;
                                    memset(jishu,0,sizeof(jishu));
                                    for(int i=1;i<=n;i++)
                                    {
                                            int a;
                                            scanf("%d",&a);
                                            jishu[a]++;
                                    }                   
                                    memset(vi,0,sizeof(vi));
                                    printf("Sums of %d:\n",t);
                                    dfs(100,0);
                                    if(chaojiflag);
                                    else
                                    printf("NONE\n");
    }
    return 0;
}
