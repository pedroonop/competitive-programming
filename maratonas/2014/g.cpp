#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define iii pair<int, ii>

int n;
char matrix[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool m(char c){
	return 'a' <= c && c <= 'j';
}

bool permite(char c, int mask){
	return (m(c) && ((1<<(c - 'a')) & ~mask)) || (!m(c) && ((1<<(c - 'A')) & mask));
}

bool valid(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int bfs(int mask){
	if (!permite(matrix[1][1], mask) || !permite(matrix[n][n], mask)) return INF;
	queue<iii> q;
	q.push(iii(1, ii(1, 1)));

	int cor[101][101];
	ms(cor, 0);
	cor[1][1] = 1;


	while (!q.empty()){
		iii topo = q.front();
		q.pop();
		int d = topo.ff;
		int x = topo.ss.ff;
		int y = topo.ss.ss;
		if (x == n && y == n) return d;
		for (int i = 0; i < 4; i++){
			int x_ = x + dx[i], y_ = y + dy[i];
			if (valid(x_, y_) && cor[x_][y_] == 0 && permite(matrix[x_][y_], mask)){
				cor[x_][y_] = 1;
				q.push(iii(d + 1, ii(x_, y_)));
			}
		}
	}

	return INF;
}

int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf(" %c", &matrix[i][j]);
		}
	}

	int minimo = INF;
	for (int mask = 0; mask < 1024; mask++){
		minimo = min(minimo, bfs(mask));
	}

	if (minimo != INF) printf("%d\n", minimo);
	else printf("-1\n");

	return 0;
}