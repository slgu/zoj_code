#include<iostream>
#include<map>
#include<string>
using namespace std;
double graph[35][35],distance2[35][35];
double min(double a,double b)
{
    return a>b?b:a;
}
int main()
{
  map <string,int> mp;
  int n,m,count=0;
 a: while(cin >> n,n)
  {
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        graph[i][j]=(i==j)?0:999999;
      for(int i=1;i<=n;i++)
   {
       string s;
       cin>>s;
       mp[s]=i;
   }
   cin >> m;
   for(int i=1;i<=m;i++)
   {
     string p,q;
     double k;
     cin>>p;
     cin>>k;
     cin>>q;
     if(mp[p]==mp[q])
     {
         if(k>1)
         {
             cout<<"Case "<<++count<<": Yes"<<endl;
            goto a;
         }
        else
          continue;
     }
     distance2[mp[p]][mp[q]]=graph[mp[p]][mp[q]]=1/k;
   }
   for(int k=1;k<=n;k++)
   for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
        if(i!=k&&j!=k&&i!=j)
        {
            distance2[i][j]=min(distance2[i][j],distance2[i][k]*distance2[k][j]);
            distance2[j][i]=min(distance2[j][i],distance2[j][k]*distance2[k][i]);
        }
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    if(distance2[i][j]*distance2[j][i]<1)
    {
        cout<<"Case "<<++count<<": Yes"<<endl;
        goto a;
    }
                  cout<<"Case "<<++count<<": No"<<endl;
  }
  return 0;
}
