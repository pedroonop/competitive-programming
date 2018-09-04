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

int main(){

	int n;
	while (scanf("%d", &n) == 1){

		int v[10001];

		lld cont = 0;

		go (i, n){
			scanf("%d", &v[i]);
			cont += v[i];
		}

		if (cont % n != 0){
			printf("-1\n");
			continue;
		}

		int i = 0, j = n - 1;
		int obj = cont / n;

		lld operacoes = 1;
		while (v[i] == obj) i++;
		while (v[j] == obj) j--;
		while (i < j){
			int mudanca = min(obj - v[i], v[j] - obj);
			v[i] += mudanca;
			v[j] -= mudanca;
			operacoes += mudanca;
			while (v[i] == obj) i++;
			while (v[j] == obj) j--;
		}

		printf("%lld\n", operacoes);
	}


	return 0;
}