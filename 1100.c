/*DP,不会*/
#include<stdio.h>
#include<string.h>
long long sum[12][1<<11];
void search(int b, int state, int base);
int qq,stage,h,w;;
const int bit[] = {1, (1 << 1), (1 << 2), (1 << 3), (1 << 4), (1 << 5),(1 << 6), (1 << 7), (1 << 8), (1 << 9), (1 << 10)};
int main()
{
	int c;
	while(scanf("%d%d",&h,&w)&&(h||w))
	{
		qq=1<<w;
		memset(sum,0,sizeof(sum));
		sum[0][0]=1;
		stage=1;
		search(0,0,0);
		for(stage=2;stage<=h;stage++)
			for(c=0;c<qq;c++)
				if(sum[stage-1][c])
					search(0,0,c);
		printf("%lld\n",sum[h][0]);
	}
	return 0;
}
void search(int b, int state, int base)
{
	if(b==w)
	{
		sum[stage][state]+=sum[stage-1][base];
		return;
	}
	if(base&bit[b])
		search(b+1,state,base);
	else
	{
		if(b+1<w&&!(bit[b+1]&base))
		{
			search(b+2,state,base);
		}
		state|=bit[b];
		search(b+1,state,base);
	}
}