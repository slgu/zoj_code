#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[25],t[25],r[25];
int n;

int work(int v);

int main()
{
int i,j,a,v,low,high;
int m;
cin>>m;
while(m--)
{
   memset(t,0,sizeof(t));
   for(i=0;i<24;i++)
    cin>>r[i];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
    cin>>a;
    t[a]++;
   }
   low=0,high=n;
   while(low<high)
   {
    v=(low+high)>>1;
    if(work(v))
     high=v;
    else
     low=v+1;
   }
   if(work(high))
    cout<<high<<endl;
   else
    cout<<"No Solution\n";
}
return 0;
}

int work(int v)
{
int i,k,flag;
memset(s,0,sizeof(s));
for(k=0;k<=24;k++)
{
   flag=0;
   if(s[0]>t[0])
   {
    flag=1;
    s[0]=t[0];
   }
   if(s[23]<v)
   {
    flag=1;
    s[23]=v;
   }
   for(i=23;i>=1;i--)
   {
    if(s[i-1]<s[i]-t[i])
    {
     flag=1;
     s[i-1]=s[i]-t[i];
    }
   }
   for(i=1;i<=23;i++)
   {
    if(s[i]<s[i-1])
    {
     flag=1;
     s[i]=s[i-1];
    }
   }
   for(i=8;i<=23;i++)
   {
    if(s[i]<s[i-8]+r[i])
    {
     flag=1;
     s[i]=s[i-8]+r[i];
    }
   }
   for(i=0;i<=7;i++)
   {
    if(s[i]<s[i+16]+r[i]-v)
    {
     flag=1;
     s[i]=s[i+16]+r[i]-v;
    }
   }
   if(!flag)break;
}
if(!flag&&s[23]==v)return 1;
return 0;
}
