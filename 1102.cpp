#include<cstdio>
#include<cstring>
char seq[1100][1100];
int n,l;
int heap[2200];
int main()
{
    while(scanf("%d%d",&n,&l)&&(n||l))
    {
                                      int cost=0;
                                      for(int i=1;i<=n;i++)
                                      scanf("%s",seq[i]);
                                      for(int k=1;k<=l;k++)
                                      {
                                              for(int i=1;i<=n;i++)
                                              heap[n+i-1]=1<<(seq[i][k-1]-'A');
                                              for(int i=n-1;i>=1;i--)
                                              {
                                                      if(heap[i]=(heap[2*i]&heap[2*i+1]));
                                                      else
                                                      {
                                                      heap[i]=heap[2*i]|heap[2*i+1];
                                                      cost++;
                                                      }
                                              }
                                              char ch='A';
                                              while(heap[1]>>=1)++ch;
                                              printf("%c",ch);
                                      }     
                                      printf(" %d\n",cost);
                                              
    }                                  
    return 0;
} 
