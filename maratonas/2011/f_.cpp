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
#define INF ~(1<<31)
#define ff first
#define ss second

int main(){

	int n;
	ii obj[1000001];

	while (scanf("%d", &n) == 1){

		go (i, n){
			scanf("%d %d", &obj[i].ff, &obj[i].ss);
		}

		sort(obj, obj + n);

		int minimo = obj[0].ff;
		int primeiro = 0;
		while (primeiro < n && obj[primeiro].ff == minimo) primeiro++;
		
		int cont = 1;
		int alcancado = obj[primeiro - 1].ss, maximo = obj[primeiro - 1].ss;

		for (int i = primeiro; i < n; i++){
			if (obj[i].ff > alcancado + 1){
				alcancado = maximo;
				cont++;
			}
			if (maximo < obj[i].ss){
				maximo = obj[i].ss;
			}
		}

		if (alcancado < maximo){
			cont++;
		}

		printf("%d\n", cont);
		
	}


	return 0;
}