#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <queue>
#include <ctime>
#include <bitset>
using namespace std;
template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1) t = x; if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1) t = x; if (x > t) t = x;}
typedef pair <int,int> PII;
typedef pair <double,double> PDD;
typedef long long LL;
#define foreach(it,v) for (__typeof((v).begin()) it = (v).begin();it != (v).end();it++)
#define DEBUG(a) cout << #a" = " << (a) << endl;
#define DEBUGARR(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

const LL mod = 1000000007;
LL n, k;
LL pow(LL x, LL y){
	x %= mod;
	LL t = 1;
	while(y){
		if(y & 1)
			t = (t * x) % mod;
		y >>= 1;
		x = (x * x) % mod;
	}
	return t;
}
int main(){
	while(~scanf("%lld%lld", &n, &k)){
		printf("%lld\n", pow(pow(2, k) - 1, n));
	}
	return 0;
}
