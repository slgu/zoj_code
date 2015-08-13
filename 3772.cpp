#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
ll c[400010][2][2];
const ll mod = 1e9 + 7;
void mul(ll a[2][2], ll b[2][2], ll c[2][2]){
	for(int i  = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			c[i][j] = 0;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;

}
ll v[100010];
void build(int i, int l, int r){
	if(l == r){
		c[i][0][0] = 1;
		c[i][0][1] = v[l + 1];
		c[i][1][0] = 1;
		c[i][1][1] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	mul(c[2 * i + 1], c[2 * i], c[i]);
}
void qu(int i, int l, int r, int x, int y, ll res[2][2]){
	if(l == x && r == y){
		for(int k1 = 0; k1 < 2; ++k1)
			for(int k2 = 0; k2 < 2; ++k2){
				res[k1][k2] = c[i][k1][k2];
						}
			return;
	}
	int m = (l + r) >> 1;
	if(m >= y)
		qu(2 * i, l, m, x, y, res);
	else
		if(m < x)
			qu(2 * i + 1, m + 1, r, x, y, res);
		else
		{
			ll left[2][2];
			ll right[2][2];
			qu(2 * i, l, m, x, m, left);
			qu(2 * i + 1, m + 1, r, m + 1, y, right);
			mul(right, left, res);
		}
}
int t;
int n, m;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			scanf("%lld", v + i);
		build(1, 1, n - 2);
		while(m--){
			int l;
			int r;
			scanf("%d%d", &l, &r);
			if(r == l || r == l + 1)
				printf("%lld\n", v[r - 1]);
			else{
				ll a[2][2];
				qu(1, 1, n - 2, l, r - 2, a);
				ll ans = (a[0][0] * v[l] + a[0][1] * v[l - 1]) % mod;
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}