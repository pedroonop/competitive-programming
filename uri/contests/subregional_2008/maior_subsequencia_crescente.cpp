#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 10010
#define go(i,n) for (int i = 1; i <= (int) n; i++)
#define goK(i,n,k) for (int i = 1; i <= (int) n-k; i++)
#define lld long long int
using namespace std;

lld v[602][602];
int memo[602][602];
int memo2[602][602];
int n, m;
int dp (int i, int j, int tam){
	return 0;
}

void calcula (int i, int j){
	memo[i][j] = 1;
	for (int k = j+1; k <= m; k++){
		if (v[i][k] > v[i][k-1]) memo[i][j]++;
		else break;
	}
}

void calcula2 (int i){
	memo[i][m] = 1;
	for (int j = m-1; j >= 1; j--){
		memo[i][j] = 1;
		if (v[i][j] < v[i][j+1]) memo[i][j] += memo[i][j+1];
	}
}



void mostra (){
	go(i,n){
		go(j,m){
			printf ("%d ", memo[i][j]);
		}
		printf("\n");
	}
}

int main (){
	while (scanf ("%d %d", &n, &m) == 2){
		if (n == 0) break;
		//memset (memo, 0, sizeof(memo));
		go(i,n){
			go(j,m){
				scanf ("%lld", &v[i][j]);
			}
		}
		/*
		go(i,n){
			go(j,m){
				calcula(i,j);
			}
		}*/
		go(i,n){
			calcula2(i);
		}
		int ans = -INF;
		//mostra();
		go (k,m){
			go(i,n){
				go(j,m-k+1){
					memo2[i][j] = 0;
					if (memo[i][j] >= k) memo2[i][j] = k;
					if (v[i-1][j+k-1] < v[i][j] && memo[i-1][j] >= k && j + k-1 <= m) memo2[i][j] += memo2[i-1][j];
					ans = max(ans, memo2[i][j]);
				}
			}
		}
		//mostra();
		printf ("%d\n", ans);
	}
	return 0;
}
