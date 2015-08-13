#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
typedef long long LL;
map< pair <LL, LL >, pair<LL , LL> > mp;
LL n;
LL prime[50010], is[50010];
void getprime(){
	int cnt = 0;
	for(int i = 2; i <= 50000; i++){
		if( !is[i] ){
			prime[cnt++]=i;
			for(int j = i; j <= 50000; j += i)
				is[j]=1;
		}
	}
}
LL pow(LL x, LL y){
	LL tmp = 1;
	while(y){
		if(y & 1) tmp = tmp * x;
		x = x * x;
		y >>= 1;
	}
	return tmp;
}
LL dfs(LL i, LL n){
	if( mp.count(make_pair(i, n)) ) 
		return mp[ make_pair(i, n) ].first;
	if(prime[i] > n){
		mp[ make_pair(i, n) ].first = 1;
		mp[ make_pair(i, n) ].second = 1;
		return 1;
	}
	LL tmp = prime[i] , cnt = 0, ans = 0;
	while( tmp <= n ){
		cnt++;
		if(ans < (cnt + 1) * dfs(i+1, n / tmp)){
			mp[ make_pair(i, n) ].second = tmp * mp[ make_pair(i+1, n / tmp) ].second;
			ans = (cnt + 1) * mp[ make_pair(i+1, n / tmp) ].first;
		}
		else {
			if( ans == (cnt + 1) * mp[ make_pair(i+1, n / tmp) ].first)
				if(mp[ make_pair(i, n) ].second > tmp * mp[ make_pair(i+1, n / tmp)].second)
				mp[ make_pair(i, n) ].second = tmp * mp[ make_pair(i+1, n / tmp)].second;
		}
		tmp *= prime[i];
	}
	return mp[ make_pair(i,n) ].first = ans;
}
int main(){
	getprime();
	mp.clear();
	while(~scanf("%lld",&n)){
		dfs(0, n);
		printf("%lld\n", mp[ make_pair(0,n)].second);
	}
	return 0;
}
