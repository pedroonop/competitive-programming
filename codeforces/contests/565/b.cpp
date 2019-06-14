#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)(n); i++)
#define go1(i, n) for (int i = 1; i <= (int)(n); i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){

	int t;

	scanf("%d", &t);

	while (t--){
		int n;
		int m[4];
		int aux;

		scanf("%d", &n);
		m[0] = m[1] = m[2] = 0;
		go (i, n){
			scanf("%d", &aux);
			aux = aux % 3;
			m[aux]++;
		}

		int minimo = min(m[1], m[2]);
		int result = m[0] + minimo;
		m[1] -= minimo;
		m[2] -= minimo;

		result += (m[1] + m[2]) / 3;

		printf("%d\n", result);		
	}


	return 0;
}