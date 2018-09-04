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
#define MAXN 25

int v[MAXN];
map <int, int> m;

int main(){

	int n;
	while (scanf ("%d", &n) == 1){
		m.clear();
		m[INF] = INF;
		v[n] = INF;
		go(i,n){
			scanf ("%d", &v[i]);
		}
		go(i,n){
			int aux;
			scanf ("%d", &aux);
			m[aux] = i+1;
		}
		int ans = 0;
		go(i,n){
			go(j,n){

				if (m[v[j]] > m[v[j+1]]){
					swap(v[j], v[j+1]);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}