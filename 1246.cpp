#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int out[100];
string str;
int change(string s)
{
	int ans=0;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		ans=10*ans+s[i]-'0';
	}
	return ans;
}
int main()
{
	int n,pro=0;
	cin>>n;
	while(n--)
	{
		memset(out,0,sizeof(out));
		int index[100];
		int j=0;
		while(cin>>str)
		{
			if(str=="BEGIN")
				continue;
			if(str=="LOOP")
			{
				cin>>str;
				if(str[0]=='n')
					index[++j]=-1;
				else
				{
					int a=change(str);
					index[++j]=a;
				}
			}	
			if(str=="OP")
			{
				cin>>str;
				int xishu=1;
				int cishu=0;
				if(str[0]=='n')
					cishu++;
				else
				{
					int a=change(str);
					xishu*=a;
				}
					for(int i=j;i>=1;i--)
					{
						if(index[i]>=0)
							xishu*=index[i];
						else
							cishu++;
					}
				out[cishu]+=xishu;
			}
			if(str=="END")
				j--;
			if(j==-1)
				break;
		}
		printf("Program #%d\nRuntime = ", ++pro);
		
		
		         int   flag = 0;
		            for (j = 10; j > 1; j--)
		            {
		                            if (out[j])
		                            {
		                                                if (flag) printf("+");
		                            
		                                                if (out[j] != 1)
		                                                     printf("%d*n^%d", out[j], j);
		                                                else
		                                                     printf("n^%d", j);
		                            
		                                                flag = 1;
		                                            }
		                        }
		
		            if (out[1])
		            {
		                            if (flag) printf("+");
		            
		                            if (out[1] != 1)
		                                 printf("%d*n", out[1]);
		                            else
		                                 printf("n");
		            
		                            flag = 1;
		                        }
		
		            if (out[0])
		            {
		                            if (flag) printf("+");
		                            printf("%d", out[0]);
		            
		                            flag = 1;
		                        }
		            if (flag == 0) printf("0");
		                        printf("\n\n");
	}
	return 0;
}
