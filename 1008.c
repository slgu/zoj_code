#include <stdio.h>
#include <string.h>
int block[25][4];
int num[25];
int kase=0;
int putIn[25];
int n;
int ccount=0;
int DFS(int pos)
{
	if (pos==n*n)
		return 1;
	int i;
	for (i=0;i<ccount;++i)
	{
		if (num[i]==0)
			continue;
		if (pos%n!=0)
		{
			if (block[putIn[pos-1]][1]!=block[i][3])
			{
				continue;
			}
		}
		if (pos/n!=0)
		{
			if (block[putIn[pos-n]][2]!=block[i][0])
			{
				continue;
			}
		}
		putIn[pos]=i;
		num[i]--;
		if (DFS(pos+1)==1)
		{
			return 1;
		}
		num[i]++;
	}
	return 0;
}
int main()
{
	int first=1;
	while (1)
	{
		scanf("%d",&n);
		if (n==0)
			break;
		memset(num,0,sizeof(num));
		if (first)
			first=0;
		else
			printf("\n");
		int t,r,b,l;
		ccount=0;
		int i;
		for (i=0;i<n*n;i++)
		{
			scanf("%d%d%d%d",&t,&r,&b,&l);
			int j=0;
			while (j<ccount)
			{
				if (block[j][0]== t && block[j][1]==r && block[j][2]==b && block[j][3]==l)
				{
					num[j]++;
					break;
				}
				j++;
			}
			if (j==ccount)
			{
				block[j][0]=t;
				block[j][1]=r;
				block[j][2]=b; 
				block[j][3]=l;
				num[j]++;
				ccount++;
			}
		}
		if (DFS(0)==1)
		{
			printf("Game %d: Possible\n",++kase);
		}
		else
			printf("Game %d: Impossible\n",++kase);
	}
	return 0;
}
