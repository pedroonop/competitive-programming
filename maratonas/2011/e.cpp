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

int estacionado[1001];

int search(int c, int s){
	int vago = 0;
	for (int i = 1; i <= c; i++){
		if (estacionado[i] == 0){
			vago++;
		}
		else{
			vago = 0;
		}
		if (vago >= s){
			return i - s + 1;
		}
	}
	return -1;
}

void apagar(int placa, int c){
	bool flag = false;
	for (int i = 1; i <= c; i++){
		if (estacionado[i] == placa){
			estacionado[i] = 0;
			flag = true;
		}
		else if (flag) return;
	}
}

int main(){

	int c, n;

	while (scanf("%d %d", &c, &n) == 2){

		memset(estacionado, 0, sizeof(estacionado));

		lld cont = 0;

		for (int i = 0; i < n; i++){
			char op;
			int placa;
			scanf(" %c %d", &op, &placa);
			if (op == 'C'){
				int tam;
				scanf("%d", &tam);
				int vaga = search(c, tam);
				if (vaga != -1){
					cont++;
					for (int j = vaga; j < vaga + tam; j++){
						estacionado[j] = placa;
					}
				}
			}
			else{
				apagar(placa, c);
			}
		}

		printf("%lld\n", 10 * cont);
		
	}

	return 0;
}