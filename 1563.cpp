#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
#define MAXN 110
int a[MAXN], p[MAXN], T, n, need[MAXN];
int dp[100010];
inline void checkmin(int & a, int b){
	if(b == -1)return;
	if(a == -1) a = b;
	else
		a = ( a < b) ? a : b;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			scanf("%d%d", a + i, p + i);
		}
		partial_sum(a + 1, a + n + 1, need + 1);
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for(int i = 1; i <= n; i++){
			for(int  j = 100000; j >= 0; j--){
				if(dp[j] != -1)
				checkmin(dp[need[i]], dp[j] + (need[i] - j + 10) * p[i]);
			}
		}
		printf("%d\n",dp[need[n]]);
	}
	return 0;
}
