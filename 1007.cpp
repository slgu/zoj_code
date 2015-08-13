#include <cstdio>
double get_res(double x){
		double ans = 0;
		double j;
		for(j = 1; j < 10000; j++){
			ans += 1 / (j * (j + 1) * (j + 2) * (j + x));
		}
		ans = 1 + (1 - x) * ((2 - x) * ans + 0.25);
	return ans;
}
int main(){
	double x = 0.0;
	for(int i = 0; i < 2001; i++){
		printf("%5.3f %16.12f\n", x, get_res(x));
		x += 0.001;
		getchar();
	}
	return 0;
}
