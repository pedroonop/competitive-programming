#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
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

int main(){

	int n;
	cin >> n;

	int qtd[27];
	for (int i = 0; i < 26; i++){
		qtd[i] = 0;
	}

	string aux;
	for (int i = 0; i < n; i++){
		cin >> aux;
		qtd[aux[0] - 'a']++;
	}

	int x= 0;

	for (int i = 0; i < 26; i++){
		int metade = qtd[i]>>1;
		if (qtd[i] & 1){
			x += ((metade * (metade + 1))>>1) + ((metade * (metade - 1))>>1);
		}
		else{
			x += metade * (metade - 1);
		}		
	}

	printf("%d\n", x);

	return 0;
}