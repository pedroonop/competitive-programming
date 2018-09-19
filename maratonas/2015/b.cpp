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
#define MAXN 200000

int n, custo;
int v[MAXN + 1], c[MAXN + 1];

int M[MAXN + 1][2];
int dp(int i, bool compra){
	if (M[i][compra] != -1) return M[i][compra];
	if (i == n) return 0;
	if (compra){
		return M[i][compra] = max(dp(i + 1, true), dp(i + 1, false) + v[i]);
	}
	return M[i][compra] = max(dp(i + 1, false), dp(i + 1, true) - c[i]);
}

int main(){

	scanf("%d %d", &n, &custo);

	for (int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		c[i] = v[i] + custo;
	}

	ms(M, -1);

	printf("%d\n", dp(0, false));

	return 0;
}