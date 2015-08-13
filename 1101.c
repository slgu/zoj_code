#include<stdlib.h>
#include<stdio.h>
int n;
int a[1010];
int psort(int a[],int s,int t)
{
	int key=a[t];
	int i=s-1,j;
	for(j=s;j<t;j++)
	{
		if(a[j]<=key)
		{
			i++;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	i++;
	int temp=a[i];
	a[i]=a[t];
	a[t]=temp;
	return i;
}
void  sort(int a[],int s,int t)
{
	if(s>=t)
		return;
	int l=psort(a,s,t);
	sort(a,s,l-1);
	sort(a,l+1,t);
}
int binarysearch(int num,int a[],int l,int r)
{
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]==num)
			return 1;
		if(a[mid]>num)
			r=mid-1;
		else
			l=mid+1;
	}
	return 0;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		int i,j,k;
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a,1,n);
		int flag=0;
		for(i=n;i>=1;i--)
		{
			if(flag)
				break;
			for(j=1;j<=n;j++)
			{
				if(flag)
					break;
				if(i==j)
					continue;
				for(k=j+1;k<=n;k++)
				{
					if(flag)
						break;
					if(k==i)
						continue;
					int sum=a[i]-a[j]-a[k];
					if(sum==a[i]||sum==a[j]||sum==a[k])
						continue;
					if(binarysearch(sum,a,1,n))
					{
						printf("%d\n",a[i]);
						flag=1;
						break;
					}
					
				}
			}
		}
		if(!flag)
			printf("no solution\n");
	}
	return 0;
}