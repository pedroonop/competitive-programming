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
#define MAXN 10000000
using namespace std;

int cut[3];

int dp[4010];

int main (){
	
	int n;
	scanf ("%d", &n);
	go(i,n){
		dp[i+1] = -INF;
	}
	go(i,3){
		scanf ("%d", &cut[i]);
		for (int j = cut[i]; j <= n; j++){
			dp[j] = max(dp[j], dp[j-cut[i]]+1);
		}
	}
	printf("%d\n", dp[n]);
	
	return 0;
}
