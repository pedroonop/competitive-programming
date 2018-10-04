#include <bits/stdc++.h>
#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define MAXN 100100
using namespace std;

int memo[MAXN];
int v[MAXN];
int main (){
	int n;
	scanf ("%d", &n);
	go(i,n){
		cin >> v[i];
		
	}
	int maior = -1;
	for (int i = n-1; i >= 0; i--){
		memo[i] = 1;
		if (v[i] < v[i+1]) memo[i] += memo[i+1];
		maior = max (maior, memo[i]);
	}
	printf("%d\n", maior);
	return 0;
}
