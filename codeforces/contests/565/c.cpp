#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)(n); i++)
#define go1(i, n) for (int i = 1; i <= (int)(n); i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)

int n;
int vet[500001];
int M[7][500001];

int main(){

	scanf("%d", &n);

	if (n == 0){
		printf("0\n");
		return 0;
	}

	go (i, n){
		scanf("%d", &vet[i]);
		if (vet[i] == 4) vet[i] = 0;
		else if (vet[i] == 8) vet[i] = 1;
		else if (vet[i] == 15) vet[i] = 2;
		else if (vet[i] == 16) vet[i] = 3;
		else if (vet[i] == 23) vet[i] = 4;
		else vet[i] = 5;
	}

	go (i, 6){
		M[i][0] = 0;
	}
	if (vet[0] == 0) M[0][0]++;

	for (int i = 1; i < n; i++){
		if (vet[i] == 0) M[0][i] = M[0][i - 1] + 1;
		else M[0][i] = M[0][i - 1];
		for (int j = 1; j < 6; j++){
			if (vet[i] == j) M[j][i] = min(M[j][i - 1] + 1, M[j - 1][i - 1]);
			else M[j][i] = M[j][i - 1];
		}
	}

	go (i, 6){
		go (j, n){
			printf("%2d ", M[i][j]);
		}
		printf("\n");
	}

	int minimo = M[5][n - 1];

	printf("%d\n", n - (6 * minimo));

	return 0;
}
