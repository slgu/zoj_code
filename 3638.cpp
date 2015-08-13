#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
#define ll long long 
#define mod 100000007
const int N=10000050;
int fac[N];
void init()
{
    fac[0]=1;
    for (int i=1;i<N;i++)
        fac[i]=(ll)fac[i-1]*i%mod;
}
int modexp(int a,int b)
{
    int ret=1;
    while (b)
    {
        if (b&1) ret=(ll)ret*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ret;
}
int inv(int a,int m)
{
    return modexp(a,m-2);
}
int C(int n,int m)
{
    if (m>n) return 0;
    int a=fac[n];
    int b=(ll)fac[m]*fac[n-m]%mod;
    return (ll)a*inv(b,mod)%mod;
}
char s[105];
int les[20];
char s1[20],s2[20],s3[20];
int main()
{
    init();
    int num;
    int n,m;
    gets(s);
    while (1)
    {
        while(!isdigit(s[0])) gets(s);
        sscanf(s,"%d%d",&n,&m);
        if (n==0) break;
        int lcnt=0;
        bool flag=true;
        while(gets(s))
        {
            if (!isalpha(s[0])) break;
            sscanf(s,"%s%s%s%d",s1,s2,s3,&num);
            if (s2[0]=='g')
            {
                m-=(num+1);
                if (m<0) flag=false;
            }
            if (s2[0]=='l')
            {
                les[lcnt++]=num;
                if (num==0) flag=false;
            }
        }
        if (!flag){puts("0");continue;}
        
        int ans=C(m+n-1,n-1);
        
        int bd=(1<<lcnt)-1;
        for (int i=1;i<=bd;i++)
        {
            int tp=0,cnt=0;
            for (int j=0;j<lcnt;j++)
            {
                if ((i>>j)&1)
                {
                    cnt++;
                    tp+=les[j];
                }
            }
            int tmp=C(m-tp+n-1,n-1);
            if (cnt&1)
                ans=((ans-tmp)%mod+mod)%mod;
            else ans=(ans+tmp)%mod;
        }
        printf("%d\n",ans);
    }    
}
 