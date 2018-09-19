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
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){

	int n;
	scanf("%d", &n);

	ii vet[3001];

	go (i, n){
		scanf("%d %d", &vet[i].x, &vet[i].y);
	}

	sort(vet, vet + n);

	lld cont = 0;

	for (int i = 0; i < n; i++){
		int maximo = INF, minimo = -INF;
		for (int j = i + 1; j < n; j++){
			if (vet[j].y > vet[i].y){
					if (vet[j].y < maximo){
					cont++;
					maximo = vet[j].y;
				}
			}
			else if (vet[j].y > minimo){
				cont++;
				minimo = vet[j].y;
			}
		}
	}

	printf("%lld\n", cont);

	return 0;
}