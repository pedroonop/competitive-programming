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
#define MAXC 100000
#define MAXN 10000

int c, n, tam;
int qtd[MAXC + 1];

bool corte_pss(int corte){
	int fim = corte + tam;
	if (corte == 0 && qtd[fim - 1] != 1) return false;
	while (fim < c){
		if (qtd[fim - 1] - qtd[fim - tam - 1] != 1) return false;
		fim += tam;
	}
	return true;
}

int main(){

	while (scanf("%d %d", &c, &n) == 2){
		tam = c / n;

		int azeitonas[MAXN + 1];
		go (i, n){
			scanf("%d", azeitonas + i);
		}

		int atual = 0;
		if (azeitonas[0] == 0){
			qtd[0] = 1;
			atual++;
		}
		else{
			qtd[0] = 0;
		}

		for (int i = 1; i < c; i++){
			qtd[i] = qtd[i - 1];
			if (atual < n && i == azeitonas[atual]){
				atual++;
				qtd[i]++;
			}
		}

		bool flag = false;
		for (int corte = 0; corte < tam; corte++){
			if (!flag && corte_pss(corte)){
				flag = true;
			}
		}

		if (flag) printf("S\n");
		else printf("N\n");		
	}

	return 0;
}