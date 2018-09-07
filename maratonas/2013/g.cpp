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
#define MAXN 300

int matriz[MAXN + 10][MAXN + 10];

int main(){
	int l, n;

	while (scanf("%d %d", &l, &n) == 2){
		go (i, l){
			go (j, n){
				scanf("%d", &matriz[i][j]);
				matriz[i][j]--;
			}
		}

		int cont = 0;
		go (k, l){
			go (i, l){
				if (i != matriz[i][0] / n) cont++;
				swap(matriz[i], matriz[matriz[i][0] / n]);
			}			
		}

		go (j, n){
			if (j != matriz[0][j] % n) cont++;
			int dest = matriz[0][j] % n;
			go (i, l){
				swap(matriz[i][j], matriz[i][dest]);
			}
		}

/*		go (i, l){
			go (j, n){
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
		}*/

		bool flag = true;
		go (i, l){
			if (i != l - 1 && matriz[i][n - 1] > matriz[i + 1][0]) flag = false;
			go (j, n - 1){
				if (matriz[i][j] > matriz[i][j + 1]) flag = false;
			}
		}

		if (flag) printf("%d\n", cont);
		else printf("*\n");		
	}


	return 0;
}