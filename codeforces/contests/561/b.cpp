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

char mat[10000][10000];

int main(){

	int k;
	scanf("%d", &k);

	int n = -1, m = -1;
	for (int i = 5; i * i <= k; i++){
		if (k % i == 0){
			n = i;
			m = k / i;
			break;
		}
	}

	if (n == -1){
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			mat[i][j] = 0;
		}
	}

	int maior = max(n, m);

	for (int i = 0; i < maior; i++){
		mat[i % n][i % m] = 'a';
	}
	for (int i = 0; i < maior; i++){
		mat[(i + 1) % n][i % m] = 'e';
	}
	for (int i = 0; i < maior; i++){
		mat[(i + 2) % n][i % m] = 'i';
	}
	for (int i = 0; i < maior; i++){
		mat[(i + 3) % n][i % m] = 'o';
	}
	for (int i = 0; i < maior; i++){
		mat[(i + 4) % n][i % m] = 'u';
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (mat[i][j] != 0) printf("%c", mat[i][j]);
			else printf("p");
		}
	}
	printf("\n");

	return 0;
}
