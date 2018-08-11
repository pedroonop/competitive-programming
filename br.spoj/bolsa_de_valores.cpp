#include <bits/stdc++.h>
using namespace std;
map <int, int> compras;
map <int, int> vendas;
int main (){
	int n;
	long long int cont = 0;
	int a,b;
	char op;
	while (scanf ("%d", &n) == 1){
		if (n == 0) return 0;
		compras.clear();
		vendas.clear();
		cont = 0;
		while (n--){
			//cont = 0;
			scanf (" %c %d.%d", &op, &a, &b);
			int valor = (a * 100) + b;
			//printf ("valor = %d\n", valor);
			if (op == 'C'){
				int inicio = 0, fim = valor, ans = -1;
				while (inicio <= fim){
					int mid = (fim+inicio) >> 1;
					if (vendas.lower_bound(mid) != vendas.end() && vendas.lower_bound(mid)->first <= valor){
						ans = mid;
						fim = mid-1;
					}
					else{
						inicio = mid+1;
					}
				}
				if (ans != -1) {
					cont += valor - vendas.lower_bound(ans)->first;
					if (vendas.lower_bound(ans)->second > 1) vendas.lower_bound(ans)->second--;
					else vendas.erase(vendas.lower_bound(ans));
					/*printf ("entrou COM %d VALOR %d\n", vendas.lower_bound(ans)->first, valor);*/
				}
				else compras[valor] += 1;
			}
			else{
				int inicio = valor, fim = 50000, ans = -1;
				while (inicio <= fim){
					int mid = (fim+inicio) >> 1;
					if (compras.lower_bound(mid) != compras.end() && compras.lower_bound(mid)->first >= valor){
						ans = mid;
						inicio = mid+1;
					}
					else{
						fim = mid-1;
					}
				}
				if (ans != -1){
					cont += (compras.lower_bound(ans)->first - valor);
					if (compras.lower_bound(ans)->second > 1) compras.lower_bound(ans)->second--;
					else compras.erase(compras.lower_bound(ans));
				}
				else{
					vendas[valor] += 1;
				}
			}
		}
		printf ("%lld.%.2lld\n", cont/100, cont%100);
	}
	return 0;
}
