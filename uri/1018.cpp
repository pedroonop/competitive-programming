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

	printf("%d\n", n);
	printf("%d nota(s) de R$ 100,00\n", n / 100);
	n = n % 100;

	printf("%d nota(s) de R$ 50,00\n", n / 50);
	n = n % 50;

	printf("%d nota(s) de R$ 20,00\n", n / 20);
	n = n % 20;

	printf("%d nota(s) de R$ 10,00\n", n / 10);
	n = n % 10;

	printf("%d nota(s) de R$ 5,00\n", n / 5);
	n = n % 5;

	printf("%d nota(s) de R$ 2,00\n", n / 2);
	n = n % 2;

	printf("%d nota(s) de R$ 1,00\n", n);

	return 0;
}