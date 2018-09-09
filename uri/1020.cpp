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

int main(){

	int n;
	scanf("%d", &n);

	printf("%d ano(s)\n", n / 365);
	n = n % 365;

	printf("%d mes(es)\n", n / 30);
	n = n % 30;

	printf("%d dia(s)\n", n);

	return 0;
}