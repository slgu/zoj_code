#include <cstdio>
typedef long long LL;
int prime[1100], is[1100];
int x, y;
void getprime(){
	int cnt = 0;
	for(int i = 2; i <= 1000; i++){
		if(!is[i]){
			prime[cnt++] = i;
			for(int j = i + i; j <= 1000; j += i)
				is[j] = 1;
		}
	}
}
LL get(int x){
	if(x == 1)
		return 1;
	LL tmp = 1;
	for(int i = 0; prime[i] * prime[i] <= x; i++){
		if(x % prime[i] == 0){
			tmp <<= 1;
		}
		while(x % prime[i] == 0)x /= prime[i];
	}
	if(x != 1)
		tmp <<= 1;
	return tmp;
}
int main(){
	getprime();
	while(~scanf("%d%d", &x, &y)){
		if(y % x){
		puts("0");
		continue;
		}
		LL t = y / x;
		printf("%lld\n",get(t));
	}
	return 0;
}
