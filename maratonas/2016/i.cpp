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
#define MAXN 50000

int main(){

	int n;
	scanf("%d", &n);

	int h[MAXN + 10];

	for (int i = 1; i <= n; i++){
		scanf("%d", &h[i]);
	}

	int ed[MAXN + 10], de[MAXN + 10];

	ed[1] = 1;
	for (int i = 2; i <= n; i++){
		ed[i] = min(h[i], ed[i - 1] + 1);
	}

	de[n] = 1;
	for (int i = n - 1; i >= 1; i--){
		de[i] = min(h[i], de[i + 1] + 1);
	}

	int maximo = 0;
	for (int i = 1; i <= n; i++){
		maximo = max(maximo, min(ed[i], de[i]));
	}

	printf("%d\n", maximo);

	return 0;
}