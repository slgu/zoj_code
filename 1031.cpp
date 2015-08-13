# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;
#define N 5000
int U[N],D[N],R[N],L[N];
int H[N],C[N],S[60];
int head,size;
void build(int r,int c)
{
    C[size]=c;S[c]++;
    U[size]=U[c]; D[U[c]]=size;
    D[size]=c; U[c]=size;
    if(H[r]==-1) H[r]=R[size]=L[size]=size;
    else
    {
        L[size]=L[H[r]]; R[L[H[r]]]=size;
        R[size]=H[r]; L[H[r]]=size;
    }
    size++;
}
void remove(int &c)
{
    for(int i=D[c];i!=c;i=D[i])
    {
        R[L[i]]=R[i];
        L[R[i]]=L[i];
    }
}
void resume(int &c)
{
    for(int i=U[c];i!=c;i=U[i])
    {
        R[L[i]]=i;
        L[R[i]]=i;
    }
}
int h()
{
    int i,j,k,ret=0;
    char vis[55];
    MEM(vis);
    for(i=R[head];i!=head;i=R[i])
    {
        if(!vis[i])
        {
            ret++;vis[i]=1;
            for(j=D[i];j!=i;j=D[j])
                for(k=R[j];k!=j;k=R[k])
                    vis[C[k]]=1;
        }
    }
    return ret;
}
int ans;
void dfs(int dep)
{
    int i,j,c,min;
    if(R[head]==head)
    {
        if(dep<ans) ans=dep;
        return ;
    }
    if(dep+h()>ans)
        return ;
    for(i=R[head],min=N;i!=head;i=R[i])
        if(S[i]<min)
        {
            min=S[i];
            c=i;
        }
    remove(c);
    R[L[c]]=R[c]; L[R[c]]=L[c];
    for(i=D[c];i!=c;i=D[i])
    {
        R[L[i]]=i; L[R[i]]=i;
        for(j=R[i];j!=i;j=R[j])
            remove(j);
        dfs(dep+1);
        for(j=L[i];j!=i;j=L[j])
            resume(j);
        R[L[i]]=R[i]; L[R[i]]=L[i];
    }
    R[L[c]]=c; L[R[c]]=c;
    resume(c);
}
int b[60];
char flag[50];
int main()
{
    int t,n,m,i,j,k,col;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        MEM(flag);
        for(i=0;i<m;i++)
        {
            scanf("%d",&k);
            flag[k]=1;
        }
        col=n*(n+1)*(2*n+1)/6;
        for(i=0;i<=col;i++)
        {
            R[i]=i+1;L[i]=i-1;
            U[i]=i;D[i]=i;
            S[i]=0;
        }
        MEME(H);
        head=0;size=col+1;
        col=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i+1;j++)
                for(k=1;k<=n-i+1;k++)
                {
                    int tag=0,r=0,p;
                    for(p=k;p<k+i&&!tag;p++)
                    {
                        if(flag[(j-1)*(2*n+1)+p])
                            tag=1;
                        b[r++]=(j-1)*(2*n+1)+p;
                        if(flag[(j+i-1)*(2*n+1)+p])
                            tag=1;
                        b[r++]=(j+i-1)*(2*n+1)+p;
                    }
                    for(p=j;p<j+i&&!tag;p++)
                    {
                        if(flag[(2*p-1)*n+p+k-1])
                            tag=1;
                        b[r++]=(2*p-1)*n+p+k-1;
                        if(flag[(2*p-1)*n+p+k+i-1])
                            tag=1;
                        b[r++]=(2*p-1)*n+p+k+i-1;
                    }
                    if(!tag)
                    {
                        for(p=0;p<r;p++)
                            build(b[p],col);
                        col++;
                    }
                }
        }
        R[col-1]=0;L[0]=col-1;
        ans=N;
        dfs(0);
        printf("%d\n",ans);
    }
}
