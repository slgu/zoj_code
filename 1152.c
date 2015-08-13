#include<stdio.h>

#include<stdlib.h>

#include<string.h>

 

int main(void)

{

      int m,n,a,b,N,count,temp,ncase;

      double d;

      scanf("%d",&N);

 

      while(N -- > 0)

      {

           ncase = 0;

           while(scanf("%d%d",&n,&m) != EOF && (n||m) )

           {

                 ncase++;

                 count = 0;

                 for(a = 1; a < n - 1; a++)

                 {

                      for(b = a + 1;b < n; b++)

                      {

                            if(!((a * a + b * b + m) % (a * b)))

                                  count ++;  

                      }

                 }

                 printf("Case %d: %d\n",ncase,count);

           }

 

           if(N)

                 printf("\n");

      }

      return 0;

}
