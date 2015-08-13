/*打表，递归*/ 
#include<cstdio>
int num[20] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 
     742900, 2674440, 9694845, 35357670, 129644790, 477638700}; 
void find(int n,int &l,int &r)
{
    int le,re,j,k; 
    int temp=n;
    int count;
    for(count=1;;count++)
    {
                         temp-=num[count];
                         if(temp<=0)
                         break;
    }
    temp+=num[count];
    for(le=0;count-le-1>=0;le++)
    {
                   temp-=num[le]*num[count-le-1]; 
                   if(temp<=0)
                   break;
    }
    re=count-le-1;
    l=r=-1;
    for(j=0;j<le;j++)l+=num[j];
    for(j=0;j<re;j++)r+=num[j];
    temp+=num[le]*num[re];
    l+=(temp+num[re]-1)/num[re];
    int add=temp%num[re];
    if(add==0)
    add=num[re];
    r+=add;
}
void gao(int n)
{
     if(n==0)
              return;
     if(n==1)
     {
             printf("X");
             return; 
     } 
     int l,r;
     find(n,l,r);
     if(l>0)
     {
            printf("(");
            gao(l);
            printf(")");
     } 
     printf("X");
     if(r>0)
     {
            printf("(");
            gao(r);
            printf(")");
     } 
} 
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
                           gao(n);
                           printf("\n");
    }
    return 0;
}
