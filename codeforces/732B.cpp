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

int v[MAXN];


int main (){
	int n, k;
	scanf ("%d %d", &n, &k);
	go(i,n){
		scanf ("%d", &v[i]);
	}
	
	int ans = 0;
	int aux;
	go(i,n-1){
		aux = 0;
		if (k-(v[i]+v[i+1]) > 0){
			aux += k-v[i]-v[i+1];
			v[i+1] += aux;
		}
		ans += aux;
	}
	
	printf("%d\n", ans);
	go(i,n){
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}
