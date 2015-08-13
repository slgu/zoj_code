#include<stdio.h>
#include<math.h>
struct _point 
{
	int x;
	int y;
}point[160],p;
double dist(struct _point a,struct _point b)
{
	return (double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int state(struct _point a,struct _point b,struct _point c);
int max(int a,int b)
{
	return (a>b)?a:b;
}
int main()
{
	int a,b,i,j,n,max0,temp1,temp2;
	double r;
	while(scanf("%d%d%lf",&a,&b,&r)&&r>=0)
	{	
		max0=0;
		p.x=a;
		p.y=b;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&point[i].x,&point[i].y);
		for(i=0;i<n;i++)
		{
			temp1=temp2=0;
			if(dist(p,point[i])>r*r)
				continue;
			for(j=0;j<n;j++)
				if(dist(p,point[j])<=r*r)
				{
					if(state(point[i],p,point[j])==1)
						temp1++;
					if(state(point[i],p,point[j])==0)
						temp2++;
					if(state(point[i],p,point[j])==2)
						{
							temp1++;
							temp2++;
						}
				}
			if(max0<max(temp1,temp2))
				max0=max(temp1,temp2);
		}
		printf("%d\n",max0);
	}
	return 0;
}
int state(struct _point a,struct _point b,struct _point c)
{
	if(a.x!=b.x)
	{
		double k=(b.y-a.y)/(double)(b.x-a.x);
		double b0=a.y-k*a.x;
		if((double)c.y>k*(c.x)+b0)
			return 1;
		if((double)c.y<k*(c.x)+b0)
			return 0;	
		if((double)c.y==k*(c.x)+b0)
			return 2;
	}
	else 
		{
			if(c.x<a.x)
				return 1;
			if(c.x==a.x)
				return 2;
			if(c.x>a.x)
				return 0;
	}
}