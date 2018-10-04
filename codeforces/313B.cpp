#include <bits/stdc++.h>
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
#define MAXN 10000000
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

int ans;
int qtd [1000010];
string s;
 
void add(int indice){
	qtd[indice] += 1;
	if (indice-1 >= 0 && qtd[indice] && qtd[indice-1] && s[indice] == s[indice-1]) ans++;
	if (qtd[indice] && qtd[indice+1] && s[indice] == s[indice+1]) ans++;
}
void remove(int indice){
	qtd[indice] += -1;
	if (indice-1 >= 0 && !qtd[indice] && qtd[indice-1] && s[indice] == s[indice-1]) ans--;
	if (!qtd[indice] && qtd[indice+1] && s[indice] == s[indice+1]) ans--;
}


void process (vector<Query> query, int n){
	block = (int) sqrt(n);
	sort(query.begin(), query.end(), compare);
	ms(qtd,0);
	int currentL = 0, currentR = 0;
	vector<int> v (query.size());
	int L, R;
	ans = 0;
	for (Query u : query){
		L = u.l;
		R = u.r;
		while (currentL < L){
			remove(currentL);
			currentL++;
		}
		while (currentL > L){
			add (currentL-1);
			currentL--;
		}
		while (currentR <= R){
			add (currentR);
			currentR++;
		}
		while (currentR > R+1){
			remove (currentR-1);
			currentR--;
		}
		v[u.i] = ans;
	}
	for (int u : v){
		printf ("%d\n", u);
	}
}



int main (){
	cin >> s;
	vector <Query> Q;
	cin >> q;
	Query aux;
	for (int i = 0; i < q; i++){
		cin >> aux.l >> aux.r;
		aux.l--;
		aux.r--;
		aux.i = i;
		Q.push_back(aux);
	}
	process (Q, s.size());
}
