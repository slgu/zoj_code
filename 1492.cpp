//模版
#include<cstdio>
#include<cstring>
const int maxn = 55;
int p[maxn][maxn],n;
void clique(int n, int mat[][maxn], int num, int U[], int size, int C[], int& _max, int ok) {
    int i, j, k, tmp[maxn];
    if (num == 0) {
        if (size > _max) { ok = 1; _max = size; }
        return;
    }
    for (i = 0; i < num && !ok; ++i) {
        if (size + num  - i <= _max) return;
        if (size + C[U[i]] <= _max) return;
        for (k = 0, j = i + 1; j < num; ++j) if (mat[U[i]][U[j]])
            tmp[k++] = U[j];
        clique(n, mat, k, tmp, size + 1, C, _max, ok);
    }
}

int max_clique(int n, int mat[][maxn]) {
    int i, j, k, U[maxn], C[maxn], _max;
    for (_max = 0, i = n - 1; i >= 0; --i) {
        for (k = 0, j = i + 1; j < n; ++j) if (mat[i][j])
            U[k++] = j;
        clique(n, mat, k, U, 1, C, _max, 0);
        C[i] = _max;
    } return _max;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&p[i][j]);
		printf("%d\n",max_clique(n,p));
	}
	return 0;
}
