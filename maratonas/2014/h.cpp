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

int main(){

	int n, m;

	scanf("%d %d", &n, &m);

	int result = 0;
	go (i, n){
		int cont = 0;
		go (j, m){
			int aux;
			scanf("%d", &aux);
			cont += (aux != 0);
		}
		if (cont == m) result++;
	}

	printf("%d\n", result);

	return 0;
}