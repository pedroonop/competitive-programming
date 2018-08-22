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
using namespace std;

int v[602][602];
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



int f (int i, int j, int k){
	if (j + k > m) return 0;
	//printf ("i = %d  j = %d k = %d    ", i, j, k);
	int ans = 0;
	if (memo[i][j] >= k) ans += k;
	else return 0;
	i++;
	for (; i <= n; i++){
		if (v[i-1][j+k-1] >= v[i][j]) break; 
		if (memo[i][j] >= k) ans += k;
		else break;
	}
	//printf ("ans = %d\n",  ans);
	return ans;
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
		memset (memo, 0, sizeof(memo));
		go(i,n){
			go(j,m){
				scanf ("%d", &v[i][j]);
			}
		}
		go(i,n){
			go(j,m){
				calcula(i,j);
			}
		}
		int ans = -INF;
		go (k,n){
			go(i,n){
				goK(j,m,k){
					//ans = max (ans, f(i,j,k));
					if (memo[i][j] >= k) memo2[i][j]++;
					if (v[i-1][j+k-1] < v[i][j]) memo2[i][j] += memo[i-1][j];
					ans = max(ans, memo[i][j]);
				}
			}
		}
		//mostra();
		printf ("%d\n", ans);
	}
	return 0;
}
