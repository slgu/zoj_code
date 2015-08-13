#include<cstdio>
#include<cstring>
int t,n;
char s[1010];
int in[30],out[30],root[30],vi[30];
int getroot(int x)
{
    if(x==root[x])
    return x;
    return root[x]=getroot(root[x]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              memset(in,0,sizeof(in));
              memset(out,0,sizeof(out));
              memset(vi,0,sizeof(vi));
              for(int i=1;i<=26;i++)
              root[i]=i;
              for(int i=1;i<=n;i++)
              {
                      scanf("%s",s);
                      int size=strlen(s);
                      int x=s[0]-'a'+1,y=s[size-1]-'a'+1;
                      out[x]++;
                      in[y]++;
                      vi[x]=1;
                      vi[y]=1; 
                      x=getroot(x);
                      y=getroot(y);
                      if(x!=y)
                      root[x]=y;
              }
              int flag=1;
              for(int i=1;i<=26;i++)
              {
                      if(!vi[i])
                      continue;
                      for(int j=1;j<=26;j++)
                      {
                              if(!vi[j]||i==j)
                              continue;
                              int x=getroot(i),y=getroot(j);
                              if(x!=y)
                              flag=0;
                      }
              }
              if(!flag)
              {
                       printf("The door cannot be opened.\n");
                       continue;
              }
              int dif=0,ins=0,outs=0;
              for(int i=1;i<=26;i++)
              {
                      if(!vi[i])
                      continue;
                      if(in[i]!=out[i])
                      {
                                       dif++;
                                       if(in[i]==out[i]+1)
                                       ins++;
                                       if(out[i]==in[i]+1)
                                       outs++;
                      }
              }
              if(dif==2&&ins==1&&outs==1)
                                         printf("Ordering is possible.\n");
              else if(dif==0)
                                         printf("Ordering is possible.\n");
              else
                                         printf("The door cannot be opened.\n");
    }
    return 0;
} 
