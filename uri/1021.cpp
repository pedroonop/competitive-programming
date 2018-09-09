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

void solve(lld &n, lld m){
	if (m >= 200){
		printf("%lld nota(s) de R$ %lld.00\n", n / m, m / 100);
	}
	else if (m == 100){
		printf("%lld moeda(s) de R$ 1.00\n", n / m);		
	}
	else if (n > 10){
		printf("%lld moeda(s) de R$ 0.%lld\n", n / m, m);
	}
	else{
		printf("%lld moeda(s) de R$ 0.0%lld\n", n / m, m);		
	}
	n = n % m;
}

int main(){

	long double x;
	cin >> x;

	lld n = 100 * x;

	printf("NOTAS:\n");
	solve(n, 10000);
	solve(n, 5000);
	solve(n, 2000);
	solve(n, 1000);
	solve(n, 500);
	solve(n, 200);
	printf("MOEDAS:\n");
	solve(n, 100);
	solve(n, 50);
	solve(n, 25);
	solve(n, 10);
	solve(n, 5);
	solve(n, 1);

	return 0;
}