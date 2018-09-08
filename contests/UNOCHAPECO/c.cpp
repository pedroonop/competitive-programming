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
#define ms(v, x) memset(v, x, sizeof(v))
#define M 1000000007

int main(){

	llu a, b;
	scanf("%llu %llu", &a, &b);

	a = a % M;
	b = b % M;

	lld sa;
	if (a % 2){

	}

	printf("%llu\n", (((a / 2) * (a + 1)) - ((b / 2) * (b - 1))) % M);

	return 0;
}