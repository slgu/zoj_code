#include<cstdio>
#include<cstring>
#include<memory.h>
char mp[6][3][3],s[2];
int T,ansx[10],ansy[10];
int judge(char mp[6][3][3])
{
	for(int i=0;i<6;i++)
	{
		char tmp=mp[i][0][0];
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				if(tmp!=mp[i][j][k])return 0;
	}
	return 1;
}
struct node
{
	int id;
	int t[3];
	node(int ID,int a,int b,int c):id(ID)
	{
		t[0]=a,t[1]=b,t[2]=c;
	}
};
void change(char mp[6][3][3],node a,node b,node c,node d,int f)
{
	if(f)
	{
		node tp=a;
		a=d;
		d=tp;
		tp=b;
		b=c;
		c=tp;
	}
	int x,y,z,k;
	x=a.id,y=b.id,z=c.id,k=d.id;
	for(int i=0;i<3;i++)
	{
		char tp=mp[x][0][a.t[i]];
		mp[x][0][a.t[i]]=mp[y][0][b.t[i]];
		mp[y][0][b.t[i]]=mp[z][0][c.t[i]];
		mp[z][0][c.t[i]]=mp[k][0][d.t[i]];
		mp[k][0][d.t[i]]=tp;
	}
}
void rotate(char mp[3][3],int f)
{
	if(f)
	{
		char tp=mp[0][2];
		mp[0][2]=mp[0][0];
		mp[0][0]=mp[0][6];
		mp[0][6]=mp[0][8];
		mp[0][8]=tp;
		tp=mp[0][1];
		mp[0][1]=mp[0][3];
		mp[0][3]=mp[0][7];
		mp[0][7]=mp[0][5];
		mp[0][5]=tp;
	}
	else
	{
		char tp=mp[0][0];
		mp[0][0]=mp[0][2];
		mp[0][2]=mp[0][8];
		mp[0][8]=mp[0][6];
		mp[0][6]=tp;
		tp=mp[0][1];
		mp[0][1]=mp[0][5];
		mp[0][5]=mp[0][7];
		mp[0][7]=mp[0][3];
		mp[0][3]=tp;
	}
}
int dfs(char mp[6][3][3],int cnt,int dep,int pre,int predo)
{
	if(cnt>=dep)return 0;
	char tp[6][3][3];
	for(int i=0;i<6;i++)
		for(int j=0;j<2;j++)
		{
			memcpy(tp,mp,sizeof(tp));
			if((i==pre)&&(predo&j))continue;
			rotate(tp[i],j);
			switch(i)
			{
				case(0):change(tp,node(1,0,3,6),node(5,0,3,6),node(3,8,5,2),node(4,0,3,6),j&1);ansx[cnt]=i,ansy[cnt]=((j&1)?1:-1);break;
				case(1):change(tp,node(4,6,7,8),node(2,0,3,6),node(5,2,1,0),node(0,8,5,2),j&1);ansx[cnt]=i,ansy[cnt]=((j&1)?1:-1);break;
				case(2):change(tp,node(4,8,5,2),node(3,0,3,6),node(5,8,5,2),node(1,8,5,2),j&1);ansx[cnt]=i,ansy[cnt]=((j&1)?1:-1);break;
				case(3):change(tp,node(2,8,5,2),node(4,2,1,0),node(0,0,3,6),node(5,6,7,8),j&1);ansx[cnt]=i,ansy[cnt]=((j&1)?1:-1);break;
				case(4):change(tp,node(1,2,1,0),node(0,2,1,0),node(3,2,1,0),node(2,2,1,0),j&1);ansx[cnt]=i,ansy[cnt]=((j&1)?1:-1);break;
				case(5):change(tp,node(1,6,7,8),node(2,6,7,8),node(3,6,7,8),node(0,6,7,8),j&1);ansx[cnt]=i,ansy[cnt]=((j&1)?1:-1);break;
			}
			if(judge(tp))
				return 1;
			if(dfs(tp,cnt+1,dep,i,j))
				return 1;
		}
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				scanf("%s",s);
				mp[4][i][j]=s[0];
			}
		for(int i=0;i<3;i++)
			for(int j=0;j<12;j++)
			{
				scanf("%s",s);
				mp[j/3][i][j%3]=s[0];
			}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				scanf("%s",s);
				mp[5][i][j]=s[0];
			}
		if(judge(mp))
		{
			printf("0\n");
			continue;
		}
		int dep=1;
		while(dep<=5)
		{
			if(dfs(mp,0,dep,-1,-1))break;
			dep++;
		}
		if(dep==6)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",dep);
		for(int i=0;i<dep;i++)
			printf("%d %d\n",ansx[i],ansy[i]);
	}
	return 0;
}
