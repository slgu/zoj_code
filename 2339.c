#include<stdio.h>
long long n1;
long long sum,a[500002],n,N;
void swap(long long i,long long j)
{
                      long long temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;
} 
void up(long long i)
{
     if(i==1)
     return;
     else
     {
         long long j=i/2;
         if(a[j]>a[i])
         {
                      swap(i,j);
                      up(j); 
         }
     }
}
void down(long long i)
{
     if(2*i>n)
     return;
     long long j=2*i; 
     long long x=(a[i]<a[j])?i:j;
     if(2*i+1<=n)
                 x=(a[x]<a[2*i+1])?x:2*i+1; 
     if(x!=i)
     {
             swap(x,i);
             down(x);
     } 
}
int main()
{
    scanf("%lld",&n1);
    long long i,j,k; 
    while(n1--)
    {
               sum=0;
               scanf("%lld",&n);
               for(i=1;i<=n;i++)
               {
                       scanf("%lld",a+i);
                       up(i);
               }
               while(n!=1)
               {
                          long long temp=0; 
                          for(k=1;k<=2;k++)
                          { 
                                           temp+=a[1]; 
                                           sum+=a[1];
                                           swap(1,n);
                                           n--;
                                           down(1);           
                          } 
                          a[++n]=temp;
                          up(n); 
               } 
               printf("%lld\n",sum); 
               if(n1!=0)
               printf("\n"); 
    }
    return 0;
}
