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

	scanf("%d %d", &l, &n);
	go (i, l){
		go (j, n){
			scanf("%d", &matriz[i][j]);
			matriz[i][j]--;
		}
	}

	int dx[301];

	go (j, n){
		dx[j] = matriz[0][j] % n;
	}

	int dy[301];
	go (i, n){
		dy[i] = matriz[i][0] / n;
	}

	return 0;
}