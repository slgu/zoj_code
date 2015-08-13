#include<cstdio>
typedef long long LL;
LL n;
int gao(LL x)
{
    int cnt=0;
    LL t;
    while(x!=1)
    {
               if(cnt%2)
               {
                        t=x/2;
                        if(x%2)
                        t++;
               }
               else
               {
                   t=x/9;
                   if(x%9)
                   t++;
               }
               x=t;
               cnt++;
    }
    return cnt&1;
}
int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
                                printf("%s wins.\n",gao(n)?"Stan":"Ollie");
    }
} 