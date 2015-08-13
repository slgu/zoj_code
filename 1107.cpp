#include<iostream>
#include<cstring>
#include<queue> 
using namespace std;
int map[102][102];
int dp[102][102];
int  dfs(int i,int j);
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1}; 
int n,k,ans;
int inside(int a,int b)
{
    return a>=1&&a<=n&&b>=1&&b<=n;
} 
int main()
{
    while(cin>>n>>k&&!(n==-1&&k==-1))
    {
                    memset(dp,0,sizeof(dp));
                    for(int i=1;i<=n;i++)
                            for(int j=1;j<=n;j++)
                              cin>>map[i][j];
                          ans=dfs(1,1);
                          cout<<ans<<endl;
    }
    return 0;
}
int  dfs(int i,int j)
{
     if(dp[i][j])
     return dp[i][j];
     int max=0,temp;
    for(int a=0;a<4;a++)
    for(int b=1;b<=k;b++)
    { 
            int x=i+b*dx[a];
            int y=j+b*dy[a];
            if(!inside(x,y)||map[x][y]<=map[i][j])
            continue;
            if(map[x][y]>map[i][j])
            {
                                   temp=dfs(x,y);
                                   if(temp>max)
                                   max=temp;
            }
    }
    return dp[i][j]=map[i][j]+max;
}       
    

             
