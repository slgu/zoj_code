#include<cstdio>
int n;
long long h[100010];
long long l[100010],r[100010];
long long max(long long a,long long b)
{
     return a>b?a:b;
}
int main()
{
    while(scanf("%d",&n),n)
    {
                    for(int i=1;i<=n;i++)
                            scanf("%lld",h+i);
                    for(int i=1;i<=n;i++)
                    {
                            l[i]=i;
                            r[i]=i;
                    }
                    h[0]=-1;
                    h[n+1]=-1;
                    for(int i=2;i<=n;i++)
                    {
                            int j=i;
                            while(h[i]<=h[l[j]-1])
                                                  j=l[j]-1;
                            l[i]=l[j];
                    }
                    for(int i=n-1;i>=1;i--)
                    {
                            int j=i;
                            while(h[i]<=h[r[j]+1])
                            j=r[j]+1;
                            r[i]=r[j];
                    }
                    long long ans=-1;
                    for(int i=1;i<=n;i++)  
                    {
                            ans=max(h[i]*(long long)(r[i]-l[i]+1),ans);
                    }
                    printf("%lld\n",ans);          
    }
    return 0;
}
