#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
typedef long long LL;
int T,k;
LL n;
int ans[100];
string str;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>k;
		cin>>str;
		cin>>n;
		ans[k]=-1;
		while(k--)
		{
			if(n&1)
			{
				if(str[k]=='n')
					n+=2;
				ans[k]=1;
			}
			else
				ans[k]=0;
			n>>=1;
		}
		if(n!=0)
			printf("Impossible");
		else
			for(int i=0;ans[i]!=-1;i++)
				printf("%d",ans[i]);
		puts("");
	}
	return 0;
}
