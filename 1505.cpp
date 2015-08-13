#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
#define N 8 // 图的大小

int g[N][N];
int godir[][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int gtoi (int a[][N]) {
	int rs = 0;
	int loc = 10000000;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[i][j]==1) {
				rs += i*loc;
				loc /= 10;
				rs += j*loc;
				loc /= 10;
			}
			if(loc==1) 	break;
		}
		if(loc==1) 	break;
	}
	return rs;
}

void itog(int a[][N], int st) {
	for(int i = 0; i < N; ++i) memset(a[i], 0, sizeof(a[i]));
	int loc = 10000000;
	int x,y;
	for (int i = 0; i < 4; ++i) {
		x = st/loc%10;
		loc /= 10;
		y = st/loc%10;
		loc /= 10;
		a[x][y] = 1;
	}
}

void show(int a[][N]) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) printf("%d",a[i][j]);
		puts("");
	}
	puts("");
}
void show(int sta) {
	int a[N][N];
	itog(a, sta);
	show(a);
}

int findadj (vector<int> &adj, const int fr) {
	adj.clear();
	int tmp[N][N];
	int ball[4][2];
	int loc = 10000000;
	for (int i = 0; i < 4; ++i) {
		ball[i][0] = fr/loc%10;
		loc /= 10;
		ball[i][1] = fr/loc%10;
		loc /= 10;
	}
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			itog(tmp, fr);
			int x = ball[i][0] + godir[j][0];
			int y = ball[i][1] + godir[j][1];
			int flag = 1;
			if( 0 <= x && x < N && 0 <= y && y < N && tmp[x][y]!=1) {
				flag = 0;
				tmp[x][y] = 1;
				tmp[ball[i][0]][ball[i][1]] = 0;
				adj.push_back( gtoi(tmp) );
			}
			if(flag) {
				x = ball[i][0] + godir[j][0]*2;
				y = ball[i][1] + godir[j][1]*2;
				if( 0 <= x && x < N && 0 <= y && y < N && tmp[x][y]!=1) {
					tmp[x][y] = 1;
					tmp[ball[i][0]][ball[i][1]] = 0;
					adj.push_back( gtoi(tmp) );
				}
			}
		}
	}
}

int dsbfs(int src, int des) {
	int dir = 0; // 表示方向 
	int e[2]; // 目标状态 
	queue<int> que[2]; // 队列 
	/*dis 用来记录距离，由于状态只有8^8=16777216 个，但是为了方便，
	  用到了8位十进制的整数来保存，这样就有10^8=100000000 个数了，内存肯定溢出
	  所以用set来保存距离*/
	map<int, int> dis[2];
	vector<int> adj; // 寻找fr扩展的节点 
	e[0] = des,	e[1] = src; // e表示dir应该搜索的目标 
	que[0].push(src), que[1].push(des);
	dis[0][src] = 1, dis[1][des] = 1;
	/* 双向广搜 */
	while(!que[0].empty() || !que[1].empty()) {
		dir = que[0].size() <= que[1].size() ? 0 : 1; // 找节点少的队列进行扩展 
		if(que[dir].empty() && !que[!dir].empty()) dir = !dir;  // 如果一个队列为空了就找剩下一个队列
		int fr = que[dir].front();
		que[dir].pop();
		int frdis = dis[dir][fr];
		if(e[dir]==fr) { // 找到了对方 
			return frdis;
		}
		if(dis[!dir][fr]) { // 搜索到对方扩展的状态就可以返回了 
			return dis[!dir][fr] + frdis - 1;
		}
		findadj(adj, fr);
		for(int i = 0; i < adj.size(); ++i) {
			if(dis[dir][adj[i]]==0 && frdis + 1 <= 5) { // 己方搜索到的状态不会重复并且距离最短 
				dis[dir][adj[i]] = frdis + 1;
				que[dir].push(adj[i]);
			}
		}
	}
	return 0;
}

int main () {
	int x, y;
	int src, des;
	while(scanf("%d", &x) - EOF) {
		// 第一个图的输入
		scanf("%d", &y);
		memset(g, 0, sizeof(g));
		g[x-1][y-1] = 1;
		for (int i = 0; i < 3; ++i) {
			scanf("%d%d", &x, &y);
			g[x-1][y-1] = 1;
		}
		src = gtoi(g);
		memset(g, 0, sizeof(g));
		// 第二个图的输入
		for (int i = 0; i < 4; ++i) {
			scanf("%d%d", &x, &y);
			g[x-1][y-1] = 1;
		}
		des = gtoi(g);
		printf("%s\n", dsbfs(src, des)? "YES" : "NO");
	}
	return 0;
}
