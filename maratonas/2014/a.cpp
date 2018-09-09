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

int teto_div(int a, int b){
	if (a % b == 0) return a / b;
	return a / b + 1;
}

int main(){

	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", teto_div(b, (b - a)));

	return 0;
}