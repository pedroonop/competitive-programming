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

int E[61], D[61];

int main(){

	int n;

	while (scanf("%d", &n) == 1){
		int m;
		char c;

		memset(E, 0, sizeof(E));
		memset(D, 0, sizeof(D));

		lld cont = 0;
		go (i, n){
			scanf("%d %c", &m, &c);
			if (c == 'E'){
				if (D[m]){
					cont++;
					D[m]--;
				}
				else{
					E[m]++;
				}
			}
			else{
				if (E[m]){
					cont++;
					E[m]--;
				}
				else{
					D[m]++;
				}
			}
		}

		printf("%lld\n", cont);		
	}

	return 0;
}