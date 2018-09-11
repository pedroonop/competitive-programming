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

int main (){
	int n, k;
	while (cin >> n >> k){
		bool v[n+1];
		memset(v,0,sizeof v);
		go(i,k){
			int aux;
			cin >> aux;
			v[aux] = true;
		}
		int cont = 0;
		go(i,n){
			if(!v[i+1]){
				printf ("%d ", i+1);
				cont++;
			}
		}
		if(!cont) printf("*\n");
		else printf("\n");
	}
	return 0;
}
