#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char dp[5010][5010];
int main()
{
    char s[5010];
    int count;
    while(scanf("%s",s+1)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        count=0;
        int l=strlen(s+1);
        for(int i=1;i<=l;i++)
            dp[i][i]=1;
        for(int k=1;k<=l-1;k++)
        {
          for(int i=1;i+k<=l;i++)
            {
                int j=i+k;
                if(s[i]==s[j])
                {
                    if(i+1==j)
                        dp[i][j]=1;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        for(int i=1;i<=l;i++)
        for(int j=i;j<=l;j++)
        {
            if(dp[i][j])
              count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
