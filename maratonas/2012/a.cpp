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
#define MAXN 1010

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, c;

	while (cin >> n >> l >> c){
		string palavras[MAXN];
		for (int i = 0; i < n; i++){
			cin >> palavras[i];
		}

		int livre_na_linha = c;
		int livre_na_pagina = l - 1;
		int cont = 1;

		for (int i = 0; i < n; i++){
			if (livre_na_linha >= (int)palavras[i].size()){
				livre_na_linha -= (int)palavras[i].size() + 1;
			}
			else{
				if (livre_na_pagina > 0){
					livre_na_pagina--;
					livre_na_linha = c - (int)palavras[i].size() - 1;
				}
				else{
					livre_na_linha = c - (int)palavras[i].size() - 1;
					livre_na_pagina = l - 1;
					cont++;
				}
			}
		}

		cout << cont << endl;
		
	}


	return 0;
}