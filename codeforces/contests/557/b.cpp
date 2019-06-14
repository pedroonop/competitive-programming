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

int m1[51][51], m2[51][51];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	go (i, n){
		go (j, m){
			scanf("%d", &m1[i][j]);
		}
	}

	go (i, n){
		go (j, m){
			scanf("%d", &m2[i][j]);
		}
	}

	bool flag = true;

	go (i, n){
		if (!flag) break;
		for (int j = 1; j < m; j++){
			if (m1[i][j] <= m1[i][j - 1] || m2[i][j] <= m2[i][j - 1]){
				if (m1[i][j] > m2[i][j - 1] && m2[i][j] > m1[i][j - 1]){
					swap(m1[i][j], m2[i][j]);
				}
				else{
					flag = false;
					break;
				}
			}
		}
	}

	go (j, m){
		if (!flag) break;
		for (int i = 1; i < n; i++){
			if (m1[i][j] <= m1[i - 1][j] || m2[i][j] <= m2[i - 1][j]){
				if (m1[i][j] > m2[i - 1][j] && m2[i][j] > m1[i - 1][j]){
					swap(m1[i][j], m2[i][j]);
				}
				else{
					flag = false;
					break;
				}
			}
		}
	}

	if (flag){
		printf("Possible\n");
	}
	else{
		printf("Impossible\n");		
	}

	return 0;
}