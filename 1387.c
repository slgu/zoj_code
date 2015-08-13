#include<stdio.h>
#include<string.h>
#define N 10010
#define M 110
int dp[N];
char morse[N],strs[N][M];
int strnum;
char norm[27][5]= {".-","-...","-.-.","-..",
	".","..-.","--.","....",
	"..",".---","-.-",".-..",
	"--","-.","---",".--.",
	"--.-",".-.","...","-",
	"..-","...-",".--","-..-",
	"-.--","--.."};
int back_equal(int curpos,char str[])
{
	int i,j=strlen(str);
	if(curpos<j-1)return -2;
	for(i=curpos,j-=1;j>=0;i--,j--){
		if(morse[i]!=str[j])
			return -2;
	}
	return i;
}
int dp_procedure(int curpos)
{
	int i,index;
	if(curpos<0)
		return 1;
	if(dp[curpos])
		return dp[curpos];
	for(i=0;i<strnum;i++){
		if((index=back_equal(curpos,strs[i]))!=-2){
			dp[curpos]+=dp_procedure(index);
		}
	}
	return dp[curpos];
}
int main()
{
	int T,i,j,w,len,ans;
	char temp[25];
	scanf("%d",&T);
	while(T--){
		scanf("%s",morse);
		scanf("%d",&strnum);
		for(i=0;i<strnum;i++){
			scanf("%s",temp);
			strcpy(strs[i],"");
			for(w=0;temp[w];w++){
				strcat(strs[i],norm[temp[w]-'A']);
			}
		}
		len=strlen(morse);
		memset(dp,0,sizeof(int)*(len+1));
		ans=dp_procedure(len-1);
		printf("%d\n",ans);
	}
	return 0;
}