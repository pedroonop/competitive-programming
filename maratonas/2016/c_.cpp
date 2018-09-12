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

struct container{
	int conf[8];
	int custo;
	bool operator==(container a, container b){
	for (int i = 0; i < 8; i++){
		if (a.conf[i] != b.conf[i]) return false;
	}
	return true;
}
	
};


// bool operator==(container a, container b){
// 	for (int i = 0; i < 8; i++){
// 		if (a.conf[i] != b.conf[i]) return false;
// 	}
// 	return true;
// }

class comp{
public:
	bool operator()(container a, container b){
		return a.custo < b.custo;
	}	
};

class comp2{
public:
	int operator()(container a){
		ans = 347;
		for (int i = 0; i < 8; i++){
			ans += a.conf[i] * 11;
		}
		return ans;
	}
};

set<container, comp2, > visi;
priority_queue< container, vector<container>, comp > Q; 

void troca(int i, int j, container atual){
	container novo;

	for (int i = 0; i < 8; i++){
		novo.conf[i] = atual.conf[i];
	}

	novo.conf[i] = atual.conf[j];
	novo.conf[j] = atual.conf[i];
	novo.custo = atual.custo + atual.conf[i] + atual.conf[j];]

	set<container>::iterator it;

	it = visi.find(novo);

	// if (*it != visi.end()){
	// 	if (novo.custo < *it.custo){
	// 		printf("asd\n");
	// 	}
	// }

	// if (mapa.find(novo) != mapa.end()){
	// 	if (mapa[novo] > novo.custo){
	// 		printf("sjdoi\n");
	// 		mapa[novo] = novo.custo;
	// 		Q.push(novo);
	// 	}
	// }
	// else{
	// 	Q.push(novo);
	// }


}

int main(){

	container inicio;
	container destino;	


	for (int i = 0; i < 8; i++){
		scanf("%d" ,&inicio.conf[i]);
	}

	for (int i = 0; i < 8; i++){
		scanf("%d" ,&destino.conf[i]);
	}

	inicio.custo = 0;

	Q.push(inicio);

	while (!Q.empty()){
		container atual = Q.top();
		Q.pop();

		if (atual == destino){
			return atual.custo;
		}

		if (visi.find(atual) != visi.end()) continue;

		troca(0, 1, atual);
		troca(0, 4, atual);
		troca(1, 2, atual);
		troca(1, 5, atual);
		troca(2, 3, atual);
		troca(2, 6, atual);
		troca(3, 7, atual);
		troca(4, 5, atual);
		troca(5, 6, atual);
		troca(6, 7, atual);
	}

	return 0;
}