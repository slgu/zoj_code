/*DFS求出联通块,然后背包dp*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int T, m, r, x, y;
int dp[440][440], vi[440], cnt, cont[440][2];
vector <int> vt[440];
void dfs(int x, int y){
	vi[x] = 1;
	cont[cnt][y]++;
	for(int i = 0; i < vt[x].size();i++){
		int z = vt[x][i];
		if(vi[z]) continue;
		dfs(z, 1 - y);
	}
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &m, &r);
		for(int i = 0; i < 2 * m; i++)
			vt[i].clear();
		memset(cont, 0, sizeof(cont));
		memset(vi, 0, sizeof(vi));
		for(int i = 0; i < r; i++){
			scanf("%d%d", &x, &y);
			x--;
			y--;
			vt[x].push_back(y + m);
			vt[y + m].push_back(x);
		}
		cnt = 0;
		for(int i = 0; i < 2 * m; i++){
			if(!vi[i]){
				dfs(i, i / m);
				cnt++;
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 0; i < cnt; i++){
			for(int j = m / 2; j >= cont[i][0]; j--)
				for(int k = m / 2; k >= cont[i][1]; k--){
						dp[j][k] |= dp[j - cont[i][0]][k - cont[i][1]];
				}
		}
		for(int i = m / 2; i >= 0; i--){
			if(dp[i][i]){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
