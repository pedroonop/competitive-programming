#include <bits/stdc++.h>
#define mod 1000000007
#define lld long long int
int min, max, n;



lld memo[51][100010];


lld dp (int N, int exe){
	if (exe > max || exe < min) return 0;
	if (N == n-1) return 1;
	if (memo[N][exe] != -1) return memo[N][exe];
	return memo[N][exe] = ((dp(N+1, exe+1)%mod)+(dp(N+1, exe-1)%mod))%mod;
}



int main (){
	scanf ("%d %d %d", &n, &min, &max);
	memset (memo, -1, sizeof memo);

	lld ans = 0;
	for (int i = min; i <= max; i++){
		ans += dp(0,i);
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}