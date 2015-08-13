#include<cstdio>
#include<cstring>
int y,m,d;
int ju(int y)
{
	int t=y+1900;
	if((t%4==0&&t%100)||t%400==0)
		return 1;
	return 0;
}
int day[2][12]=
{
	31,28,31,30,31,30,31,31,30,31,30,31,
	31,29,31,30,31,30,31,31,30,31,30,31
};
int in(int y,int m,int d)
{
	if(y>101)
		return 0;
	if(y==101)
	{
		if(m>10)
			return 0;
		if(m==10&&d>4)
			return 0;
	}
	int t=ju(y);
	int dd=day[t][m];
	if(d>dd)
		return 0;
	return 1;
}
int  dp[110][14][40];
void inc(int &y,int &m,int &d)
{
	d++;
	if(d>day[ju(y)][m])
		d=1,m++;
	if(m>11)
		m=0,y++;
}
int dfs(int y,int m,int d)
{
	if(y==101&&m==10&d==4)
		return 0;
	if(dp[y][m][d]!=-1)
		return dp[y][m][d];
	int yy=y,mm=m,dd=d;
	inc(yy,mm,dd);
	if(in(yy,mm,dd)&&!dfs(yy,mm,dd))
		return dp[y][m][d]=1;
	yy=y,mm=m,dd=d;
	mm++;
	if(mm>11)
		mm=0,yy++;
	if(in(yy,mm,dd)&&!dfs(yy,mm,dd))
		return dp[y][m][d]=1;
	return dp[y][m][d]=0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d%d%d",&y,&m,&d);
		y-=1900;
		m--;
		printf("%s\n",(dfs(y,m,d)==0)?"NO":"YES");
	}
	return 0;
}