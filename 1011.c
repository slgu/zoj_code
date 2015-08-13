#include<stdio.h>
#include<string.h>
typedef struct signal 
{
	int left;
	int right;
	
} point;
point table[20][20][20];
int see[100][100];
char tree[1200];
char c[2];
int judge(int signal,int node);
int treedeep,n,m,k;
int main()
{
	int i,j,z,count=1;
	char ch;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		if(m==0&&n==0&&k==0)
			break;
		if(count>1)
			printf("\n");
		printf("NTA%d:\n",count);
		for(i=0;i<n;i++)
			for(j=0;j<k;j++)
			{	z=0;
				while(1)
			{
				scanf("%d%d",&table[i][j][z].left,&table[i][j][z].right);	
				ch=getchar();
				z++;
				if(ch=='\n')
					break;
			}
				see[i][j]=z;
			}
		while(scanf("%d",&z)&&z!=-1)
		{
			treedeep=0;
			for(i=0;i<=z;i++)
				for(j=1;j<=(1<<i);j++)
				{
					treedeep++;
					scanf("%s",c);
					tree[treedeep]=*c;
				}
		if(judge(0,1))
			printf("Valid\n");
		else 
			printf("Invalid\n");
		}
		count++;
	}
		
	return 0;
}
int judge(int signal,int node)
{
	int k=tree[node]-'a';
	int i=0;
	int left=node*2;
	int right=left+1;
	if(node>treedeep||tree[node]=='*')
		if(signal<n-m)
		 return 0;
		 else return 1;
	while(i<see[signal][k])
	{	
		if(judge(table[signal][k][i].left,left)&&judge(table[signal][k][i].right,right))
			return 1;
		i++;
	}
	 
		return 0;
}