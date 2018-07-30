#include <bits/stdc++.h>
#define lld long long int
#define MAXN 200010
using namespace std;
string s;
int tree[27][MAXN];
bool removido[MAXN];
void update (int i, int letra, int valor){
	for (; i <= MAXN; i += (i&-i)){ tree[letra][i] += valor;}
}

lld query (int i, int letra){
	lld ans = 0;
	for (; i; i -= (i&-i)) ans += tree[letra][i];
	return ans;
}

int main (){
	cin >> s;
	for (int i = 0; i < (int) s.size(); i++){
		update (i+1, s[i]-'a', 1);
	}
	int m, k, inicio, fim, ans;
	char x;
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> k >> x;
		ans = 0;
		inicio = 1;
		fim = s.size();
		while (inicio <= fim){
			int meio = (inicio+fim) >> 1;
			if (query(meio, x-'a') >= k){
				ans = meio;
				fim = meio-1;
			}
			else{
				inicio = meio+1;
			}
			
		}
		removido[ans] = true;
		update (ans, x-'a', -1);
	}
	
	for (int i = 0; i < (int) s.size(); i++){
		if (!removido[i+1]) printf ("%c", s[i]);
	}
	printf ("\n");
	
	
	return 0;
}
