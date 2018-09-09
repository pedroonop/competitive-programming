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

int embaralhar(int x, int n){
	if (x <= n) return x + x;
	return (x - n) * 2 - 1;
}

int main(){

	int p;
	scanf("%d", &p);

	int n = p / 2;

	int cont = 1;
	int pos = embaralhar(1, n);

	while (pos != 1){
		cont++;
		pos = embaralhar(pos, n);
	}

	printf("%d\n", cont);

	return 0;
}