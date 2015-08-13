 #include<stdio.h>
#include<string.h>
int main()
{
	int d[16],a[22][22];
	int c[22][22];

	int n,n1,k;
	scanf("%d",&n);
	memset(a,0,22*22*sizeof(int));
	int i,j,z;
	while(n--)
	{	
		scanf("%d",&n1);
		for(i=0;i<16;i++)
			scanf("%d",&d[i]);
		for(i=1;i<=20;i++)	
			for(j=1;j<=20;j++)
				scanf("%d",&a[i][j]);
		for(z=1;z<=n1;z++)
		{
			for(i=1;i<=20;i++)	
				for(j=1;j<=20;j++)
			{
				k=a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1];
				c[i][j]=k;
			}
			for(i=1;i<=20;i++)	
				for(j=1;j<=20;j++)
				{
					a[i][j]+=d[c[i][j]];
					if(a[i][j]>3)
						a[i][j]=3;
					if(a[i][j]<0)
						a[i][j]=0;
				}
		}
			k=0;
			for(i=1;i<=20;i++)	
			{
				for(j=1;j<=20;j++)
			{
				k++;
				if(a[i][j]==0)
					printf(".");
				else if(a[i][j]==1)
					printf("!");
				else if(a[i][j]==2)
					printf("X");
				else 
					printf("#");	
			}
			printf("\n");
			}
		if(n)
			printf("\n");
	}
	return 0;
}
