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

int matriz[510][510];


int f(int a, int b, int c, int d){
	if (a == 3 || b == 3 || c == 3 || d == 3) return 3;
	if (a == b && b == c && c == d && d == 0) return 0;
	if (a == b && b == c && c == d && d == 1) return 1;
	if (a == b && b == c && c == d && d == 2) return 2;

	bool preto = false;
	bool branco = false;
	if (a == 1 || b == 1 || c == 1 || d == 1) branco = true;
	if (a == 2 || b == 2 || c == 2 || d == 2) preto = true;

	if (branco && preto) return 3;
	if (branco) return 1;
	if (preto) return 2;
}



int main(){
	int n, p;
	scanf ("%d %d", &n, &p);
	go(i,p){
		int a, b;
		scanf ("%d %d", &a, &b);
		matriz[a][b] = 2;
	}
	go(i,p){
		int a, b;
		scanf ("%d %d", &a, &b);
		matriz[a][b] = 1;
	}
	int pretos = p;
	int brancos = p;
	for (int k = 2; k < n; k++){
		for (int i = 1; i <= n-k+1; i++){
			for (int j = 1; j <= n-k+1; j++){
				int aux = f(matriz[i][j], matriz[i][j+1], matriz[i+1][j], matriz[i+1][j+1]);
				if (aux == 1) brancos++;
				if (aux == 2) pretos++;
				matriz[i][j] = aux;
			}
		}
	}

	printf("%d %d\n", pretos, brancos);

	return 0;
}