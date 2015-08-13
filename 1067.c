#include<stdio.h>
struct point
{
	int x;
	int y;
	int z;
};
int distance(struct point a,struct point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}

int main()
{
	int i,j,k,min,m;
	struct point c[16];
	struct point a[100];
	for(i=0;i<16;i++)
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
	for(i=0;;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].x==-1&&a[i].y==-1&&a[i].z==-1)
			break;
	}
	for(j=0;j<i;j++)
	{
		m=0;
		min=distance(a[j],c[0]);
		for(k=0;k<16;k++)
		{
			if(distance(a[j],c[k])<min)
				{
					m=k;
					min=distance(a[j],c[k]);
			}
		}
			printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a[j].x,a[j].y,a[j].z,c[m].x,c[m].y,c[m].z);

	
	}
	return 0;
}