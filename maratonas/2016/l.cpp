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
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 200

int h, l;
int mat[MAXN + 1][MAXN + 1];
int cor[MAXN + 1][MAXN + 1];

bool isValid(int i, int j){
	return i >= 0 && i < h && j >= 0 && j < l;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y){
	cor[x][y] = 1;
	int cont = 1;
	for (int i = 0; i < 4; i++){
		int x_ = x + dx[i], y_ = y + dy[i];
		if (isValid(x_, y_) && cor[x_][y_] == 0 && mat[x][y] == mat[x_][y_]){
			cont += dfs(x_, y_);
		}
	}
	return cont;
}

int main(){


	scanf("%d %d", &h, &l);

	go (i, h){
		go (j, l){
			scanf("%d", &mat[i][j]);
			cor[i][j] = 0;
		}
	}

	int minimo = INF;
	go (i, h){
		go (j, l){
			if (cor[i][j] == 0) minimo =  min(minimo, dfs(i, j));
		}
	}

	printf("%d\n", minimo);

	return 0;
}