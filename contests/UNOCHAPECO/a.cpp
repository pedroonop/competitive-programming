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

int main () {
	int n, k;
	scanf ("%d %d", &n, &k);
	go(i,n){
		int aux;
		scanf ("%d", &aux);
		v.push_back(aux);
	}
	sort(v.rbegin(), v.rend());
	lld ans = 0;
	go(i,k){
		ans +=  v[i];
		ans %= mod;
	}
	printf ("%lld\n", ans);
	return 0;
}
