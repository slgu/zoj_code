#include<stdio.h>
#include<stdlib.h>
struct node
{
   int x,y; 
   int status; 
} number[5010];  
int cmp(const void * a,const void *b)
{
	struct node * sa=(struct node *)a;
	struct node * sb=(struct node *)b;
	if(sa->x==sb->x)
		return sa->y-sb->y;
	return sa->x-sb->x;
}
int main()
{
    int n,i,j,index,k;
    int time;
    int min; 
    scanf("%d",&n); 
    while(n--) 
    {
        time=0; 
        int n1;
        scanf("%d",&n1); 
        for(i=1;i<=n1;i++)
         {
           scanf("%d%d",&number[i].x,&number[i].y);       
           number[i].status=0; 
        } 
        qsort(number+1,n1,sizeof(struct node),cmp);
        for(i=1;i<=n1;i++)
        { 
           if(number[i].status==0)
           {
               number[i].status=1;                   
               time++; 
                k=i;
                j=i+1;
                for(;j<=n1;j++)
                 if(number[k].y<=number[j].y&&!number[j].status)
                    {
                       number[j].status=1;
                       k=j;
                    }
            }
       }                                     
       printf("%d\n",time);                         
                                
    }  
    return 0;    
} 
     
