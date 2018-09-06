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
#define linha pair<dd, dd>

lld v[10010];
lld dp[10010];


//int memo[10010][10010][2];

/*
int dp (int i, int j, bool jogador){
	if (i > j) return 0;
	if (memo[i][j][jogador] != -1) return memo[i][j][jogador];
	if (jogador) return memo[i][j][jogador] = max(dp(i+1,j,false)+v[i],dp(i,j-1,false)+v[j]);
	return memo[i][j][jogador] = min(dp(i+1,j,true),dp(i,j-1,true));
}
*/


int main (){
	int n;
	while (scanf ("%d", &n) == 1){
		go(i,n){
			scanf ("%lld", &v[i+1]);
			dp[i+1] = dp[i] + v[i+1];
		}
		for (int i = n-1; i > 0; i--)
			for (int j = i+1; j <= n; j++)
				v[j] = dp[j]-dp[i-1]-min(v[j-1], v[j]);
		printf ("%lld\n", v[n]);
	}
	
	return 0;
}
