#include <bits/stdc++.h>
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
#define MAXN 1000
using namespace std;

int memo[501][501];

int dp (int i, int j){
	if (i <= 0 || j <= 0) return 0;
	if (i == 1 && j == 1) return 0;
	
	if (memo[i][j] != -1) return memo[i][j];
	
	if (i == 1) return memo[i][j] = dp(i+1,j-2)+1;
	if (j == 1) return memo[i][j] = dp(i-2, j+1)+1;
	
	return memo[i][j] = max (dp(i+1,j-2)+1, dp(i-2,j+1)+1);
}

int main (){
	ms(memo,-1);
	int i,j;
	scanf ("%d %d", &i, &j);
	printf("%d\n", dp(i,j));
}
