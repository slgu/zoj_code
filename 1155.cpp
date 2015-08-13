#include<cstdio>
#include <iostream>
#include<cstring>
using namespace std;
int maxScore[262144]; 
const int EDGENUM[10][10] = {
	-1, 0,  1, -1, -1, -1, -1, -1, -1, -1, 
	0, -1,  2,  3,  4, -1, -1, -1, -1, -1, 
	1,  2,  -1, -1, 5, 6,  -1, -1, -1, -1, 
	-1, 3, -1, -1,  7, -1,  9, 10, -1, -1, 
	-1, 4 , 5,  7, -1,  8, -1, 11, 12, -1, 
	-1, -1,  6, -1, 8, -1, -1, -1, 13, 14, 
	-1, -1, -1,  9, -1, -1, -1, 15, -1, -1, 
	-1, -1, -1, 10, 11, -1, 15, -1, 16, -1, 
	-1, -1, -1, -1, 12, 13, -1, 16, -1, 17, 
	-1, -1, -1, -1, -1, 14, -1, -1, 17, -1, 
};
const int BIT[18] = { 1, 1<<1, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6, 1<<7, 1<<8,
	1<<9, 1<<10, 1<<11, 1<<12, 1<<13, 1<<14, 1<<15, 1<<16, 1<<17 };

struct Triangle {
	int e1, e2, e3;
};
const Triangle triangle[9] = {
	0, 1, 2,
	3, 4, 7,   2, 4, 5,    5, 6, 8,
	9, 10, 15, 7, 10, 11, 11, 12, 16, 8, 12, 13, 13, 14, 17
};
int stepscore(int x,int i);
int remainscore(int x);
int max(int x);
int main()
{
	int n,game,i,x,y,sum,j,turn,a;
	scanf("%d",&n);
    memset(maxScore,-1,sizeof(maxScore));
	while(n--)
	{
      i=1;
	  scanf("%d",&game);
      while(i<=game)
      {
         sum=0;turn=0;a=0;
         scanf("%d",&j);
         while(j--)
         {
            scanf("%d%d",&x,&y);
            int e=EDGENUM[x-1][y-1];
            sum|=BIT[e];
            int q=stepscore(sum,e);
            if(q)
            {
               if(turn==0)
                 a+=q;
            }     
            else
               turn=1-turn;
             
         }
         if(turn==0)
             a+=max(sum);
         else
             a+=remainscore(sum)-max(sum);
         if(a>4)
             printf("Game %d: A wins.\n",i);
         else
             printf("Game %d: B wins.\n",i);
        i++;
      }    
      if(n!=0)
          printf("\n");   
    }
	return 0;
}
int stepscore(int x,int i)
{
    int score=0,j;
    for(j=0;j<9;j++)
    {
        if(x&BIT[triangle[j].e1]&&x&BIT[triangle[j].e2]&&x&BIT[triangle[j].e3])
        {
            if(i==triangle[j].e1||i==triangle[j].e2||i==triangle[j].e3)
                        score++;
        } 
    }
    return score;
}
int remainscore(int x)
{
    int score=9,j;
     for(j=0;j<9;j++)
    {
        if(x&BIT[triangle[j].e1]&&x&BIT[triangle[j].e2]&&x&BIT[triangle[j].e3])
        {
                        score--;
        } 
    }
    return score;
}
int max(int x)
{
    int i;
    if(maxScore[x]>-1)
      return maxScore[x];
    if(x==262143)
      return maxScore[x]=0;
      int mm=-1,m;
    for(i=0;i<18;i++) 
    {
       if(x&BIT[i])
         continue;
         int c=x|BIT[i];
         int score=stepscore(c,i);
         if(score)
             m=score+max(c);
         else     
             m=remainscore(x)-max(c);
         if(mm<m)    
             mm=m;
     }
       return maxScore[x]=mm;
}
