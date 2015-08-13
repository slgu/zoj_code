#include <cstdio>
#include <cstring>
int T,n,a[50]; 
int main()
{
    scanf("%d",&T);
    while(T--) 
    {
             scanf("%d",&n);
             int ans=0,cnt=0;
             for(int i = 0;i < n;i++)
             {
                     int c;
                     scanf("%d",&c);
                     if(c>1)cnt++;
                     ans^=c;        
             }
             if((ans&&cnt!=0)||(!ans&&cnt==0))
             printf("John");
             else
             printf("Brother");
             puts(""); 
    } 
    return 0;
}
