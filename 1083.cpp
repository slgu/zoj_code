#include<cstdio>
#include<cstring>
struct frame
{
       int x1,x2,y1,y2;
       frame()
       {
              x1=40;x2=-1;
              y1=40;y2=-1;
       }
};
int n,m;
char mp[41][41];
int g[41][41],vi[41],gg[41][41],g1[41][41],number[41];
int solution[41];
int build(frame fp[41])
{
      int count=0;
      for(int i=0;i<26;i++)
      {
              
              int x1=fp[i].x1;
              int y1=fp[i].y1;
              int x2=fp[i].x2;
              int y2=fp[i].y2;
              
              if(vi[i])
              {
                       count++;
                       int edge=0;
                       for(int j=y1;j<=y2;j++)
                       {
                               if(gg[x1][j]!=-1&&gg[x1][j]!=i)
                               {
                                                        int k=gg[x1][j];
                                                        g[i][k]=1;
                                                        number[k]++;
                                                        g1[i][++edge]=k;
                               }
                       }
                       for(int j=y1;j<=y2;j++)
                       {
                               if(gg[x2][j]!=-1&&gg[x2][j]!=i)
                               {
                                                        int k=gg[x2][j];
                                                        g[i][k]=1;
                                                        number[k]++;
                                                        g1[i][++edge]=k;
                               }
                       }
                       for(int j=x1;j<=x2;j++)
                       {
                               if(gg[j][y1]!=-1&&gg[j][y1]!=i)
                               {
                                                        int k=gg[j][y1];
                                                        g[i][k]=1;
                                                        number[k]++;
                                                        g1[i][++edge]=k;
                               }
                       }
                       for(int j=x1;j<=x2;j++)
                       {
                               if(gg[j][y2]!=-1&&gg[j][y2]!=i)
                               {
                                                        int k=gg[j][y2];
                                                        g[i][k]=1;
                                                        number[k]++;
                                                        g1[i][++edge]=k;
                               }
                       }
                       g1[i][0]=edge;
              }
      }
      return count;
}
void topsort(int dp,int cnt)
{
     if(dp>=cnt)
     {
                for(int i=0;i<dp;i++)
                printf("%c",solution[i]+'A');
                printf("\n");
     }
     for(int i=0;i<26;i++)
     {
             if(vi[i]&&number[i]==0)
             {
                             solution[dp++]=i;
                             vi[i]=0;
                             for(int j=1;j<=g1[i][0];j++)
                             {
                                     number[g1[i][j]]--;
                             }
                             topsort(dp,cnt);
                             dp--;
                             vi[i]=1;
                             for(int j=1;j<=g1[i][0];j++)
                             {
                                     number[g1[i][j]]++;
                             }
                             number[i]=0;
             }
     }
}
int main()
{
    while(1==scanf("%d",&n))
    {
                            memset(g,0,sizeof(g));
                            memset(vi,0,sizeof(vi));
                            memset(gg,-1,sizeof(gg));
                            memset(number,0,sizeof(number));
                            memset(g1,0,sizeof(g1));
                            frame fp[41];
                            scanf("%d",&m);
                            for(int i=1;i<=n;i++)
                            scanf("%s",mp[i]+1);
                            for(int i=1;i<=n;i++)
                            for(int j=1;j<=m;j++)
                            {
                                    if(mp[i][j]=='.')
                                                     continue;
                                    int a=mp[i][j]-'A';
                                    gg[i][j]=a;
                                    vi[a]=1;
                                    if(fp[a].x1>i)fp[a].x1=i;
                                    if(fp[a].y1>j)fp[a].y1=j;
                                    if(fp[a].x2<i)fp[a].x2=i;
                                    if(fp[a].y2<j)fp[a].y2=j;
                            }
                            int cnt=build(fp);
                  /*          for(int i=0;i<=4;i++)
                            printf("%d %d %d %d\n",fp[i].x1,fp[i].y1,fp[i].x2,4fp[i].y2);
                            for(int i=0;i<26;i++)
                            if(number[i])
                            printf("%d ",i); */
                            topsort(0,cnt); 
    }
    return 0;
}
