#include <cstdio>
#include <cstring>
int n, a[25][25][25], sum[25][25][25], tot[25][25][25][25];
int main(){
	while(scanf("%d", &n), n){
	memset(sum, 0, sizeof(sum));
	memset(tot, 0, sizeof(tot));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++){
					scanf("%d", &a[i][j][k]);
					if(k == 0)
						sum[i][j][k] = a[i][j][k];
					else
						sum[i][j][k] = sum[i][j][k - 1] + a[i][j][k];
				}
		for(int h = 0; h < n; h++){
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					for(int k = j; k < n; k++)
						for(int w = j; w <= k; w++)
						tot[i][j][k][h] += sum[i][w][h];
		}
		int sum = -16000000, tmp, tp;
		for(int h1 = 0; h1 < n; h1++)
			for(int h2 = h1; h2 < n; h2++)
				for(int j = 0; j < n; j++)
					for(int k = j; k < n; k++){
						tmp = 0;
						for(int i = 0; i < n; i++){
							if(h1 == 0)
								tp = tot[i][j][k][h2];
							else
								tp = tot[i][j][k][h2] - tot[i][j][k][h1 - 1];
							if(tmp < 0)
								tmp = tp;
							else
								tmp += tp;
							if(tmp > sum)
								sum = tmp;
						}
					}
		printf("%d\n", sum);
	}
	return 0;
}
