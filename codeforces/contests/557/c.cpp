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

int primeira[100001];
int ultima[100001];

int main(){

	int n, k;

	scanf("%d %d", &n, &k);
	int vet[100001];

	go1 (i, n){
		primeira[i] = INF;
		ultima[i] = -1;
	}

	go1 (i, k){
		scanf("%d", &vet[i]);
		if (primeira[vet[i]] == INF) primeira[vet[i]] = i;
		ultima[vet[i]] = i;
	}

	int cont = 3 * n - 2;

	go1 (i, n){
		if (primeira[i] < INF){
			cont--;
		}
		if (i < n && primeira[i] < ultima[i + 1]){
			cont--;
		}
		if (i > 1 && primeira[i] < ultima[i - 1]){
			cont--;
		}
	}

	printf("%d\n", cont);

	return 0;
}