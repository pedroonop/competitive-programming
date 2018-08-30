#include <bits/stdc++.h>
#define lld long long int
#define INF 0x3f3f3f3f
#define ii pair <int, int>
#define ic pair <int, char>
#define iic pair <int, ic>
#define ZERO 4294967396
#define MAXN 8589954592
using namespace std;
 
typedef struct {
	int l,r,i,k, g,d;
}Query;
int n, q, block;

 
//int bit[MAXN];
//map <int,int> bit;

bool compare (Query x, Query y){
	if (x.l/block != y.l/block)
		return x.l/block < y.l/block;
	return x.r/block < y.r/block;
	
}
 
lld vetor[200000];
iic v[200000];
lld ans;
int qtd [1000010];
Query Q[200010];

//void update (lld i, lld



 
void add(int indice){
	ans += fabs(((qtd[indice]*2)+1)*indice);
	qtd[indice]++;
}
void remove(int indice){
	ans = ans - fabs(((qtd[indice]*2)-1)*indice);
	qtd[indice]--;
	
}
 
 
void process (Query query[], int n){
	block = (int) sqrt(n);
	sort(query, query+q, compare);
	
	int currentL = 0, currentR = 0;
	int L, R;
	ans = 0;
	for (int i = 0; i < q; i++){
		L = query[i].l;
		R = query[i].r;
		
		while (currentL < L){
			remove(vetor[currentL]);
			currentL++;
		}
		while (currentL > L){
			add (vetor[currentL-1]);
			currentL--;
		}
		while (currentR <= R){
			add (vetor[currentR]);
			currentR++;
		}
		while (currentR > R+1){
			remove (vetor[currentR-1]);
			currentR--;
		}
		//v[query[i].i] = ans;
	}
	for (int i = 0; i < q; i++){
		//cout << v[i] << '\n';
		//printf ("%lld\n", v[i]);
	}
}
 
 
int main (){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		cin >> vetor[i];
	}
	for (int i = 0; i < q; i++){
		cin >> Q[i].l >> Q[i].r >> Q[i].k >> Q[i].g >> Q[i].d;
		Q[i].l--;
		Q[i].r--;
		Q[i].i = i;
	}
	process (Q, n);
	
	return 0;
}
