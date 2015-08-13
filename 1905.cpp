#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[1000010];

int main()
{
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,".")==0)
		break;
		int i,j,flag,l;
		l=strlen(s);
		for(i=1;i<=l;i++)
		{
			if(l%i)
				continue;
			for(j=i,flag=1;j<l;j++)
			{
				if(s[j%i]!=s[j])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			break;
		}
		printf("%d\n",l/i);
	}
    return 0;
}
