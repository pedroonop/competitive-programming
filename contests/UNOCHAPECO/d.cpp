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
#define mod 1000000007
vector<int> v;
int dp[510000];
int main (){
	int n;
	while (scanf ("%d", &n) == 1){
		v.clear();
		memset(dp,0,sizeof dp);
		go(i,n){
			int aux;
			scanf ("%d", &aux);
			v.pb(aux);
		}
		v.pb(-INF);
		int maior = -1;
		for(int i = n-1; i >= 0; i--){
			dp[i] = 1;
			if (v[i] < v[i+1]) dp[i] += dp[i+1];
			//else dp[i] = max(dp[i], dp[i+1]);
			maior = max(maior, dp[i]);
		}
		printf ("%d\n", maior);
	}
	return 0;
}
