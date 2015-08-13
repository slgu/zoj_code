#include<stdio.h>
#include<string.h>
struct node
{
    int x;
	int y;
} number[220];
int mov[220];
int main()
{
	int n,i,j,time;
    scanf("%d",&n);
	while(n--)
	{
		time=0;
		int n1;
		scanf("%d",&n1);
		memset(mov,0,sizeof(mov));
		for(i=1;i<=n1;i++)
		{
			scanf("%d%d",&number[i].x,&number[i].y);
			if(number[i].x)
				number[i].x=(number[i].x+1)/2;
			else
				number[i].x/=2;
			if(number[i].y)
				number[i].y=(number[i].y+1)/2;
			else
				number[i].y/=2;
			if(number[i].x>number[i].y)
			{
				int temp;
				temp=number[i].x;
				number[i].x=number[i].y;
				number[i].y=temp;
			}
			for(j=number[i].x;j<=number[i].y;j++)
				++mov[j];
		}
		for(i=1;i<=210;i++)
			if(mov[i]>time)
				time=mov[i];
		printf("%d\n",time*10);
	}
	return 0;
}
