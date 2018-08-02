#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define MAXV 100
#define mid(l, r) 	       ((l + r) >> 1)
#define INF 0x3f3f3f3f
#define LOG 25
using namespace std;
vector <vi> g;
vi euler;
vi altura;
int first[MAXV];
ii tree[8*MAXV];
ii sqrtDeco[8*MAXV];

int potencia2[LOG];
int dp[MAXV][LOG];
int logn[MAXV];




void buildSparseTable(int n){   //O(NlogN) para construir
    // initializing sparse table
    memset(dp,-1,sizeof(dp));
    // filling base case values
    for (int i=1; i<n; i++)
        dp[i-1][0] = (altura[i]>altura[i-1]) ? i-1 : i;
 
    // dp to fill sparse table
    for (int l=1; l<15; l++)
      for (int i=0; i<n; i++)
        if (dp[i][l-1]!=-1 and dp[i+potencia2[l-1]][l-1]!=-1)
          dp[i][l] = (altura[dp[i][l-1]] > altura[dp[i+potencia2[l-1]][l-1]]) ? dp[i+potencia2[l-1]][l-1] : dp[i][l-1];
        else
             break;
}
 
int query_sparse_table(int l,int r){ //O(1) para buscar
    int d = r-l;
    int dx = logn[d];
    if (l==r) return l;
    if (altura[dp[l][dx]] > altura[dp[r-potencia2[dx]][dx]])
        return dp[r-potencia2[dx]][dx];
    else
        return dp[l][dx];
}
 
void preprocess(){  //O(N) para preprocessar
    potencia2[0] = 1;
    for (int i=1; i<18; i++)
        potencia2[i] = potencia2[i-1]*2;
 
    int val = 1,ptr=0;
    for (int i=1; i < MAXV; i++){
        logn[i] = ptr-1;
        if (val==i){
            val*=2;
            logn[i] = ptr;
			ptr++;
        }
    }
}


int LCA_sparse_table (int u, int v){ //O(1) para achar o LCA
	if (u == v) return u;
	if (first[u] > first[v]) swap(u,v);
	return euler[query_sparse_table(first[u], first[v])];
}


void build(int node, int left ,int right){ // O(N) para criar a segtree
	if(left == right){
		tree[node] = ii(altura[left], euler[left]);
		return;
	}
	int esq = 2*node+1;
	int dir = 2*node+2;
	int mid = mid(left,right);
	build(esq,left,mid);
	build(dir,mid+1,right);
	if (tree[esq].first < tree[dir].first) tree[node] = tree[esq];
	else tree[node] = tree[dir];
}

ii query(int node,int left ,int right ,int lq , int rq){ //O(logN) para buscar na segtree
	if(right < lq || left > rq)
		return ii(INF,-1);
		
	if(left >= lq && right <= rq)
		return tree[node];
	
	int mid = mid(left,right);
	ii p1 = query(2*node+1,left,mid,lq,rq); 
	ii p2 = query(2*node+2,mid+1,right,lq,rq);
	if (p1.first < p2.first) return p1;
	return p2;
}


void build_sqrt(){ //O(N) para criar a sqrt decomposition
	int block = sqrt(altura.size());
	for (int i = 0; i < block; i++) sqrtDeco[i] = ii(INF, -1);
	for (int i = 0; i < (int) altura.size(); i++){
		int indice = i/block;
		if (sqrtDeco[indice].first > altura[i]) sqrtDeco[indice] = ii(altura[i],euler[i]); 
	}
}


ii query_sqrt(int l, int r){ //O(sqrt(N) para buscar
	int block = sqrt(altura.size());
	ii ans = ii(INF, -1);
	while (l % block != 0 && l < r){
		if (ans.first > altura[l]) ans = ii(altura[l], euler[l]);
		l++;
	}
	while (l+block <= r){
		int indice = l/block;
		if (ans.first > sqrtDeco[indice].first) ans = sqrtDeco[indice];
		l += block;
	}
	
	while (l <= r){
		if (ans.first > altura[l]) ans = ii (altura[l], euler[l]);
		l++;
	}
	return ans;
	
}



void dfs (int v, int nivel){
	altura.push_back(nivel);
	euler.push_back(v);
	first[v] = euler.size()-1;
	
	for (int u : g[v]){
		dfs (u, nivel+1);
		euler.push_back(v);
		altura.push_back(nivel);
	}
}

ii LCA_segtree (int v, int u){ // O(logN)
	int l = first[v];
	int r = first[u];
	if (l > r) swap (l,r);
	return query (0, 0, altura.size()-1, l, r);
}
ii LCA_sqrt (int v, int u){ //O(sqrt(N))
	int l = first[v];
	int r = first[u];
	if (l > r) swap (l,r);
	return query_sqrt (l,r);
}



int main (){
	int n, u, v;
	scanf ("%d", &n);
	g.resize(n+1);
	for (int i = 0; i < n-1; i++){
		scanf ("%d %d", &u, &v);
		g[u].push_back(v);
	}
	dfs (1, 0);
	printf ("altura = %lu\n", altura.size());
	for (int u : euler) printf ("%d ", u);
	printf("\n");
	for (int u : altura) printf ("%d ", u);
	printf ("\n");
	for (int i = 1; i <= n; i++) printf ("%d ", first[i]);
	printf ("\n");
	build (0, 0, altura.size()-1);
	build_sqrt ();
	preprocess();
	buildSparseTable (altura.size());
	
	printf ("LCA_segtree (1,2) = %d\n", LCA_segtree(1,2).second);
	printf ("LCA_sqrt (1,2) = %d\n", LCA_sqrt(1,2).second);
	printf ("LCA_sparse (1,2) = %d\n", LCA_sparse_table(1,2));
	printf ("LCA_segtree (4,5) = %d\n", LCA_segtree(4,5).second);
	printf ("LCA_sqrt (4,5) = %d\n", LCA_sqrt(4,5).second);
	printf ("LCA_sparse (4,5) = %d\n", LCA_sparse_table(4,5));
	printf ("LCA_segtree (4,3) = %d\n", LCA_segtree(4,3).second);
	printf ("LCA_sqrt (4,3) = %d\n", LCA_sqrt(4,3).second);
	printf ("LCA_sparse (4,3) = %d\n", LCA_sparse_table(4,3));
	printf ("LCA_segtree (6,7) = %d\n", LCA_segtree(6,7).second);
	printf ("LCA_sqrt (6,7) = %d\n", LCA_sqrt(6,7).second);
	printf ("LCA_sparse (6,7) = %d\n", LCA_sparse_table(6,7));
	printf ("LCA_segtree (9,12) = %d\n", LCA_segtree(9,12).second);
	printf ("LCA_sqrt (9,12) = %d\n", LCA_sqrt(9,12).second);
	printf ("LCA_sparse (9,12) = %d\n", LCA_sparse_table(9,12));
	//printf ("LCA (6,4) = %d\n", euler[LCA_segtree(6,4).second]);
	//printf ("LCA (5,7) = %d\n", euler[LCA_segtree(5,7).second]);
	return 0;
}
