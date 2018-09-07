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

int main(){

	int n, r;

	while (scanf("%d %d", &n, &r) == 2){
		bool v[10001];

		memset(v, false, sizeof(v));

		go (i, r){
			int aux;
			scanf("%d", &aux);

			v[aux] = true;
		}

		bool flag = false;
		for (int i = 1; i <= n; i++){
			if (!v[i]){
				flag = true;
				printf("%d ", i);
			}
		}

		if (!flag) printf("*");
		printf("\n");		
	}


	return 0;
}