#include<stdio.h>
#include<string.h>
#define max(a,b) ((a)<(b))?(a):(b)
int sum[25000];
int x[5002];
void up(int i)
{
     sum[i]=sum[2*i]+sum[2*i+1];
}
void build(int i,int l,int r)
{
     if(l==r)
     {
             sum[i]=0;
             return;
     }
     int mid=(l+r)>>1;
     build(2*i,l,mid);
     build(2*i+1,mid+1,r);
}
void ud(int i,int a,int L,int R)
{
     if(L==R)
     {
             sum[i]++;
             return;
     }
     int mid=(L+R)>>1;
     if(mid>=a)
     ud(2*i,a,L,mid);
     else
     ud(2*i+1,a,mid+1,R);
     up(i);
}
int qu(int i,int l,int r,int L,int R)
{
     if(l==L&&R==r)
                   return sum[i];
     int mid=(L+R)>>1;
     if(mid>=r)
     return qu(2*i,l,r,L,mid);
     if(mid<l)
     return qu(2*i+1,l,r,mid+1,R);
     return qu(2*i,l,mid,L,mid)+qu(2*i+1,mid+1,r,mid+1,R);
}
int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
                              int s=0;
                              memset(sum,0,sizeof(sum));
                              build(1,0,n-1);
                              for(i=1;i<=n;i++)
                              {
                                               scanf("%d",x+i);
                                               s+=qu(1,x[i],n-1,0,n-1);
                                               ud(1,x[i],0,n-1);
                              }
                              int ans=s;
                              for(i=1;i<=n-1;i++)
                              {
                                      s+=(n-1-2*x[i]);
                                      ans=max(s,ans);
                              }
                              printf("%d\n",ans);
    }
    return 0;                         
}
