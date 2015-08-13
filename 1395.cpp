#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
string s;
int m,n;
int map[21][21];
int cnt;
int dfs(int i,int m)
{
    if(m==cnt&&i==0)
    return 1;
    for(int j=0;j<n;j++)
    {
            if(map[i][j])
            {
                                    map[i][j]--;
                                    map[j][i]--;
                                    if(dfs(j,m+1))
                                    return 1;
                                    map[i][j]++;
                                    map[j][i]++;
            }
    }
    return 0;
}  
int main()
{
    while(cin>>s)
    {
                 memset(map,0,sizeof(map));
                if(s=="ENDOFINPUT")
                                   break;
                cin>>m>>n;
                cnt=0; 
                getchar();
                for(int i=0;i<n;i++)
                {
                        getline(cin,s);  
                        for(int j=0;j<s.size();j++)
                        {
                                if(s[j]==' ')
                                continue;
                                int a=s[j]-'0';
                                map[i][a]++;
                                map[a][i]++;
                                cnt++; 
                        }
                }
                int ans=dfs(m,0);
                if(ans==1)
                printf("YES %d\n",cnt);
                else
                printf("NO\n");
                cin>>s;
                if(s=="END")
                continue;
    }                                   
    return 0;
}
