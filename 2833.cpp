#include<cstdio>
int root[100010];
int sum[100010];
int getroot(int  x)
{
    if(root[x]==x)
    return x;
    else
    return root[x]=getroot(root[x]);   
}
char str[2];
int main()
{
    int pro=0;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
                                   if(pro)
                                   printf("\n");
                                   printf("Case %d:\n",++pro);
                                   for(int i=1;i<=n;i++)
                                   {
                                           root[i]=i;
                                           sum[i]=1;
                                   }
                                   for(int i=1;i<=m;i++)
                                   {
                                           scanf("%s",str);
                                           if(*str=='M')
                                           {
                                                      int a,b;
                                                      scanf("%d%d",&a,&b);
                                                      a=getroot(a);
                                                      b=getroot(b);
                                                      if(a==b)
                                                      continue;
                                                      root[b]=a;
                                                      sum[a]=sum[a]+sum[b];
                                           }
                                           else
                                           if(*str=='Q')
                                           {
                                                        int c;
                                                        scanf("%d",&c);
                                                        c=getroot(c);
                                                        printf("%d\n",sum[c]);
                                           }
                                   }
    }                  
    return 0;
}
