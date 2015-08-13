#include<stdio.h>
#include<string.h>
#define minimum(a,b) ((a)>(b))?(a):(b)
long long a[500];
long long f[500];
long long min[20];
long long ten_min[8];
long long hour[26];
long long get(long long i)
{
    long long k=1;
    long long temp=i;
    while(temp!=f[i])
    {
                  k++;
                  i=f[i];        
    }
    return k;
}
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}
int main()
{
    long long i,j,k,n;
    while(scanf("%d",&n),n)
    {
                     for(i=1;i<=n;i++)
                             a[i]=i;
                     long long so=n;
                     long long s1=0,s2=0,s3=0;      
                     for(j=1;j<=24*3600;j++)
                     {       
                             long long temp=a[1];
                             so--;
                             for(i=1;i<=so;i++)
                                     a[i]=a[i+1];
                             min[++s1]=temp;
                             if(s1>=10)
                             {
                                      ten_min[++s2]=temp;
                                      for(k=9;k>=1;k--)
                                      a[++so]=min[k];
                                      s1=0;
                             }
                             if(s2>=6)
                             {
                                      hour[++s3]=temp;
                                      for(k=5;k>=1;k--)
                                      a[++so]=ten_min[k];
                                      s2=0;
                             }
                             if(s3>=24)
                             {
                                       for(k=23;k>=1;k--)
                                       a[++so]=hour[k];
                                       a[++so]=hour[24];
                                       break;
                             }        
                     }
                     for(i=1;i<=n;i++)
                             f[a[i]]=i;
                     long long minn=1;
                     for(i=1;i<=n;i++)
                                      minn=lcm(minn,get(i));
                     printf("%lld\n",minn);
    } 
    return 0;
}
