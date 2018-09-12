#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
 
typedef struct {
	int l,r,i;
}Query;
int n, q, block;
 
bool compare (Query x, Query y){
	if (x.l/block != y.l/block)
		return x.l/block < y.l/block;
	return x.r/block < y.r/block;
	
}
 
int vetor[30001];
int ans;
int qtd [1000010];
 
 
void add(int indice){
	qtd[indice]++;
	if (qtd[indice] == 1) ans += 1;
}
void remove(int indice){
	qtd[indice]--;
	if (qtd[indice] == 0) ans -= 1;
}
 
 
void process (vector<Query> query, int n){
	block = (int) sqrt(n);
	sort(query.begin(), query.end(), compare);
	
	int currentL = 0, currentR = 0, sum = 0;
	vector<int> v (query.size());
	int L, R;
	ans = 0;
	for (Query u : query){
		L = u.l;
		R = u.r;
		
		while (currentL < L){
			//sum -= vetor[currentL];
			remove(vetor[currentL]);
			currentL++;
		}
		while (currentL > L){
			//sum += vetor[currentL-1];
			add (vetor[currentL-1]);
			currentL--;
		}
		while (currentR <= R){
			//sum += vetor[currentR];
			add (vetor[currentR]);
			currentR++;
		}
		while (currentR > R+1){
			//sum -= vetor[currentR-1];
			remove (vetor[currentR-1]);
			currentR--;
		}
		//printf ("[%d, %d] = %d\n", L, R, ans);
		v[u.i] = ans;
	}
	for (int u : v){
		printf ("%d\n", u);
	}
}
 
 
int main (){
	cin >> n;
	vector <Query> Q;
	Query aux;
	for (int i = 0; i < n; i++){
		cin >> vetor[i];
		//Q.push_back(aux);
	}
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> aux.l >> aux.r;
		aux.l--;
		aux.r--;
		aux.i = i;
		Q.push_back(aux);
	}
	process (Q, n);
	
	return 0;
}
