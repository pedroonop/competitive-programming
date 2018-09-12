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
#define MAXN 10010

int f_cee[MAXN];
int f_esq[MAXN];

int f_ced[MAXN];
int f_dir[MAXN];

int cord[MAXN];
int core[MAXN];

int tam_reta_esq(int i){
	int cont = 1;
	int filho = f_cee[i];
	core[i] = 1;
	while (filho != 0){
		core[filho] = 1;
		cont++;
		filho = f_cee[filho];
	}
	return cont;
}

int tam_reta_dir(int i){
	int cont = 1;
	int filho = f_ced[i];
	cord[i] = 1;
	while (filho != 0){
		cord[filho] = 1;
		cont++;
		filho = f_ced[filho];
	}
	return cont;
}

int dfs_esq(int i){
	if (i == 0) return 0;
	int cont = 0;
	if (core[i] == 0){
		cont = tam_reta_esq(i);
	}
	cont = max(cont, dfs_esq(f_cee[i]));
	cont = max(cont, dfs_esq(f_esq[i]));
	return cont;
}

int dfs_dir(int i){
	if (i == 0) return 0;
	int cont = 0;
	if (cord[i] == 0){
		cont = tam_reta_dir(i);
	}
	cont = max(cont, dfs_dir(f_ced[i]));
	cont = max(cont, dfs_dir(f_dir[i]));
	return cont;
}

int main(){

	int n, m;

	ms(f_cee, 0);
	ms(f_ced, 0);
	ms(f_esq, 0);
	ms(f_dir, 0);
	ms(core, 0);
	ms(cord, 0);

	scanf("%d", &n);
	go (asdasdas, n){
		int i, l, k;
		scanf("%d %d %d", &i, &l, &k);
		f_esq[i] = l;
		f_cee[i] = k;
	}

	scanf("%d", &m);
	go (asdasdas, m){
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		f_ced[p] = q;		
		f_dir[p] = r;
	}

	int maiore = dfs_esq(1), maiord = dfs_dir(1);
	int raize = tam_reta_esq(1), raizd = tam_reta_dir(1);

//	printf("%d %d\n%d %d\n", maiore, maiord, raize, raizd);

	printf("%d\n", n + m - max(min(maiore, raizd), min(maiord, raize)));

	return 0;
}