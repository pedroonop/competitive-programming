#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 1001
#define vi vector <int>
#define ii pair <int,int>
#define iii pair <ii,int>
#define vii vector<ii>
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
#define lld long long int
#define iic pair <ii, char>
using namespace std;

int n,k;
vector <iic> v;

int memo[MAXN][MAXN];


int main (){
	scanf ("%d %d", &n, &k);
	memset (memo, 0, sizeof(memo));
	go(i,n){
		int a, c;
		char b;
		scanf ("%d %c %d", &a, &b,&c);
		v.push_back(iic(ii(a,c), b));
	}
	int maior = 0;
	for (int i = 0; i < k; i++) memo[0][i] = 0;
	for (int i = 1; i <= n; i++){
		memo[i][0] = 0;
		for (int j = 1; j <= k; j++){
			if (j < v[i-1].ff.ss || v[i-1].ss == 'G'){
				memo[i][j] = memo[i-1][j];
			}
			else{
				memo[i][j] = max (memo[i-1][j-v[i-1].ff.ss]+v[i-1].ff.ff, memo[i-1][j]);
			}
		}
	}
	maior = max (memo[n][k], maior);
	//memset (memo, 0, sizeof(memo));
	for (int i = 0; i < k; i++) memo[0][i] = 0;
	for (int i = 1; i <= n; i++){
		memo[i][0] = 0;
		for (int j = 1; j <= k; j++){
			if (j < v[i-1].ff.ss || v[i-1].ss == 'B'){
				memo[i][j] = memo[i-1][j];
			}
			else{
				memo[i][j] = max (memo[i-1][j-v[i-1].ff.ss]+v[i-1].ff.ff, memo[i-1][j]);
			}
		}
	}
	maior = max (memo[n][k], maior);
	//memset (memo, 0, sizeof(memo));
	for (int i = 0; i < k; i++) memo[0][i] = 0;
	for (int i = 1; i <= n; i++){
		memo[i][0] = 0;
		for (int j = 1; j <= k; j++){
			if (j < v[i-1].ff.ss || v[i-1].ss == 'C'){
				memo[i][j] = memo[i-1][j];
			}
			else{
				memo[i][j] = max (memo[i-1][j-v[i-1].ff.ss]+v[i-1].ff.ff, memo[i-1][j]);
			}
		}
	}
	maior = max (memo[n][k], maior);
	printf ("%d\n", maior);
}
