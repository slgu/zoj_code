#include<stdio.h>
#include<string.h>
#define maxn 100
int main()
{
    char s[maxn];
    while(scanf("%s",s)!=EOF)
    {
                             int index=0,i,j,num;
                             char d[maxn]={'0'};
                             for(i=strlen(s)-1;i>1;i--)
                             {
                                                       num=s[i]-'0';
                                                       int temp;
                                                       for(j=0;j<index||num;j++)
                                                       {
                                                                                temp=10*num+((j<index)?d[j]-'0':0);
                                                                                d[j]=temp/8+'0';
                                                                                num=temp%8;
                                                       }
                                                       index=j;
                             }
                             printf("%s [8] = 0.%s [10]\n",s,d);                                                    
    }
    return 0;
} 
