#include<stdio.h>
#include<string.h>
int  s,w,c,k,m;
int heap[11000],in;
void swap(int *a,int *b)
{
     int temp=*a;
     *a=*b;
     *b=temp;
}
void heaplify(int i)
{
     int j=i;
     int l=2*i,r=2*i+1;
     if(l<=k&&heap[l]<heap[i])
                              i=l;
     if(r<=k&&heap[r]<heap[i])
                              i=r;
     if(i!=j)
     {
             swap(&heap[i],&heap[j]);
             heaplify(i);
     }
} 
int main() 
{
    while(5==scanf("%d%d%d%d%d",&s,&w,&c,&k,&m))
    {
              int time=9999/c+1,i;
              if(k>time)k=time; 
              for(i=1;i<=k;i++)
              heap[i]=i*m+s;
              int total=0;
              for(i=1;i<=time;i++)
              {
                      if(total<heap[1])
                      total=heap[1];
                      total+=w;
                      heap[1]+=2*s+w;
                      heaplify(1);
              }
              printf("%d\n",total+s);
    }
    return 0;
} 
