#include<iostream>
using namespace std;
int father[30010];
int people[30010];
int find(int x);
int main()
{
    int n,m,count;
    while(cin>>n>>m&&!(m==0&&n==0))
    {
        count=1;
        for(int i=0;i<=n-1;i++)
        father[i]=i;
        for(int i=1;i<=m;i++)
        {
            int k;
            cin>>k;
            for(int i=1;i<=k;i++)
                cin>>people[i];
            for(int i=2;i<=k;i++)
            {
                father[people[1]]=find(people[1]);
                father[people[i]]=find(people[i]);
                father[father[people[1]]]=father[people[i]];
            }
        }
        for(int i=1;i<=n-1;i++)
        if(find(i)==find(0))
        count++;
        cout<<count<<endl;
    }
    return 0;
}
int find(int x)
{
    if(father[x]!=x)
       father[x]=find(father[x]);
    return father[x];
}
