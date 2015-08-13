#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char line[40];
struct dict
{
	char s[12];
	char d[12];
} dt[100010];
int cmp(const void *a,const void *b)
{
	return strcmp((*(dict *)a).s,(*(dict *)b).s);
}
int bmp(const void *a,const void *b)
{
	return  strcmp((char *)a,(*(dict *)b).s);
}
int main()
{
	int cnt=0;
	int fl=0;
	while(gets(line))
	{
		if(line[0]=='\0')
		{
			fl=1;
			qsort(dt,cnt,sizeof(dict),cmp);
			continue;
		}
		if(fl==0)
		{	
			sscanf(line,"%s%s",dt[cnt].d,dt[cnt].s);
			cnt++;
		}
		else
		{
			dict *p=(dict *)bsearch(line,dt,cnt,sizeof(dict),bmp);
			if(p==NULL)
			printf("eh\n");
			else
			printf("%s\n",p->d);
		}
	}
	return 0;
}