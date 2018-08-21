#include <bits/stdc++.h>
#define lld long long int
int N;
lld memo[100];
lld f (int n){
	if (n+2 > N) return 0;
	//printf ("n = %d   N = %d\n", n, N);
	if (memo[n] != -1) return memo[n];
	lld ans = 1;
	for (int i = n+3, w = 0; i <= N; i++, w++){
		for (int j = i; j <= N; j++){
			ans += f(j+1);
		}
		ans++;
	}
	return memo[n] = ans;
}


int main (){
	scanf ("%d", &N);
	memset (memo, -1, sizeof(memo));
	lld ans = 0;
	for (int i = 1; i <= N; i++){
		ans += f(i);
	}
	printf("\n");
	printf ("%lld\n", ans+1);
	return 0;
}
