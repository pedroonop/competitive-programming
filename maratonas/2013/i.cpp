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
#define MAXN 1000000

lld M[MAXN + 1];
bool furo[MAXN + 1];
int t1, t2;
int minimo;

lld f(int c){
	if (c < minimo) return 0;
	if (c == minimo) return M[c] = min(t1, t2);
	if (M[c] != -1) return M[c];
	if (!furo[c]) return M[c] = f(c - 1);
	return M[c] = min(t1 + f(c - t1 - 1), t2 + f(c - t2 - 1));
}

int main(){

	int n, c;

	while (scanf("%d %d %d %d", &n, &c, &t1, &t2) == 4){
		memset(furo, false, c * sizeof(bool));

		memset(M, -1, c * sizeof(lld));

		minimo = INF;
		go (i, n){
			int aux;
			scanf("%d", &aux);
			furo[aux] = true;
			minimo = min(minimo, aux);
		}


		printf("%lld\n", f(c - 1));		
	}


	return 0;
}