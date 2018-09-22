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


lld v[100001];

int main (){
	int n;
	scanf("%d", &n);
	go(i,n){
		int aux;
		scanf ("%d", &aux);
		v[aux] += aux;
	}
	for (int i = 2; i <= 100000; i++){
		v[i] = max (v[i-1], v[i]+v[i-2]);
	}
	printf("%lld\n", v[100000]);
	return 0;
}
