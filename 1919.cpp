#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char a[1001][22];
int ans[1001];
bool mark[1001];
int in[26];
int out[26];
int b[26];
int root[26];
int m,ff;
int cmp(const void *a,const void *b)
{
     return(strcmp((char*)a,(char*)b));
}

void dfs(int x,int y)//x==index,y==num
{

int i,n;
if(ff)
   return;
ans[y]=x;
mark[x]=true;
if(y==m)
{
   ff=1;
   return;
}
n=strlen(a[x]);

if(b[a[x][n-1]-'a']==-1)
   return;

for(i=b[a[x][n-1]-'a'];i<=m;i++)
{
  
   if(a[i][0]!=a[x][n-1])
    break;
   if(mark[i])
    continue;
   dfs(i,y+1);
   if(ff)
    break;
}
mark[x]=false;
}

int getroot(int x)
{
if(root[x]==x)
   return x;
else return root[x]=getroot(root[x]);
}

void Union(int x,int y)
{
root[x]=y;
}

int main()
{
//freopen("debug\\in.txt","r",stdin);
int repeat,i,j,dif,i1,i2,flag;
cin>>repeat;
while(repeat--)
{
   cin>>m;
   memset(in,0,sizeof(in));
   memset(out,0,sizeof(out));
   for(i=0;i<26;i++)
    root[i]=i;
   for(i=1;i<=m;i++)
    scanf("%s",&a[i]);
   qsort(a+1,m,sizeof(a[1]),cmp);
  

   for(i=1;i<=m;i++)
   {
    out[a[i][0]-'a']++;
    in[a[i][strlen(a[i])-1]-'a']++;
    if(getroot(a[i][0]-'a')!=getroot(a[i][strlen(a[i])-1]-'a'))
    Union(a[i][0]-'a',a[i][strlen(a[i])-1]-'a');
   }
  
   i1=i2=-1;
   dif=0;
   for(i=0;i<26;i++)
   {
    if(in[i]!=out[i])
    {
     dif++;
     if(in[i]+1==out[i])//out
      i1=i;
     if(out[i]+1==in[i])
      i2=i;
    }
   }
  
   flag=1;
   for(i=0;i<26;i++)
   {
    if(in[i]||out[i])
    {
     for(j=0;j<26;j++)
     {
      if(!in[j]&&!out[j])
       continue;
      if(getroot(i)!=getroot(j))
       flag=0;
     }
     break;
    }
   }
  

   if(dif!=0&&dif!=2)
    flag=0;
   if(dif!=0&&(i1==-1||i2==-1))
    flag=0;
   if(!flag)
   {
    printf("***\n");
    continue;
   }

  
  
   memset(b,-1,sizeof(b));
   memset(mark,0,sizeof(mark));
   for(i=1;i<=m;i++)
   {
    if(b[a[i][0]-'a']==-1)
     b[a[i][0]-'a']=i;
   
   }
  
   ff=0;
   for(i=b[i1];i<=m;i++)
   {
   dfs(i,1);
   if(ff)
    break;
   }
  

   for(i=1;i<=m;i++)
   {
    printf("%s",a[ans[i]]);
    if(i<m)
    printf(".");
    else printf("\n");
   
   }
}
return 0;
}

