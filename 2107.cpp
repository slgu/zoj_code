/*采用的分治法,然后归并,合并的时候只要按照y值排序的情况进行向上最多7个点进行检查即可*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
struct point{
	double x,y;
	friend bool operator < (point a, point b){
		return a.x < b.x;
	}/*定义排序准则*/
}p[100010], sy[100010], c[100010];
double dis(point a, point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int n;
using namespace std;
const double inf = 999999999.99;
/*y轴排序数组的类似归并的构造*/
void merge(int l, int r){
	int m = (l + r) >> 1;
	int i = l, j = m + 1;
	int cnt = 0;
	while(i <= m && j <= r){//归并的操作
		if(sy[i].y > sy[j].y){
			c[cnt++] = sy[j];
			j++;
		}
		else
			if(sy[i].y < sy[j].y){
				c[cnt++] = sy[i];
				i++;
			}
			else{
				c[cnt++] = sy[i];
				c[cnt++] = sy[j];
				i++;
				j++;
			}
	}
	while(i <= m){
		c[cnt++] = sy[i++];
	}
	while(j <= r){
		c[cnt++] = sy[j++];
	}
	cnt = 0;
	for(int k = l; k <= r; k++)
		sy[k] = c[cnt++];
}
double deal(int l, int r){
	if(l == r)
		return inf;//一个点返回inf
	if(r - l == 1){
		merge(l, r);
		return dis(p[l], p[r]);
	}
	int m = (l + r) >> 1;
	double minn = min(deal(l, m), deal(m + 1, r));//分治得出两边的最小值
	merge(l, r);
	for(int i = l; i < r; i++){
		for(int k = i + 1; k <=r && k <= i + 7; k++)//向上检查最多7个点
			minn = min(minn, dis(sy[i], sy[k]));
	}
	return minn;
}
int main(){
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; i++){
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		sort(p, p + n);//先按照x进行排序
		for(int i = 0; i < n; i++)
			sy[i] = p[i];//sy数组是按照y进行排序的
		printf("%.2f\n", deal(0, n - 1) / 2);
	}	
	return 0;
}
