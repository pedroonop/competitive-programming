#include <bits/stdc++.h>
#define mod 1000000007
int N, k;
int dp[2002][2002];



int main (){
	scanf ("%d %d", &N, &k);
	dp[0][1] = 1;
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= N; j++){
			for (int k = j; k <= N; k += j){
				dp[i][k] += dp[i-1][j];
				dp[i][k] %= mod;
			}
		}
	}
	int ans = 0;
	for (int j = 1; j <= N; j++){
		ans += dp[k][j];
		ans %= mod;
	}
	printf ("%d\n", ans);
	return 0;
}
