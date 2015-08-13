#include<iostream>
#include<cstring>
#include<map>
#include<iterator>
#include<vector>
using namespace std;
int present[500010];
int front[500010];
int up[500010];
map<int,int> mp;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        mp.clear();
        memset(front ,0,sizeof(front));
        memset(up,0,sizeof(up));
        for(int i=1;i<=n;i++)
        {
            cin>>present[i];
            if(mp.find(present[i])!=mp.end())
            {
                front[i]=mp[present[i]];
                mp[present[i]]=i;
                up[i]=max(up[i-1],front[i]);
            }
            else
              {
                  mp[present[i]]=i;
                  up[i]=up[i-1];
              }
        }
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int left,right;
            cin>>left>>right;
            if(up[right]<left)
                cout<<"OK"<<endl;
            else
                cout<<present[up[right]]<<endl;
        }
        cout<<endl;

    }
    return 0;
}
