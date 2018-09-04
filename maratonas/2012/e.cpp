#include <bits/stdc++.h>
#define lld long long int
#define llu unsigned long long int
using namespace std;

char s[30];
lld memo[30][2][2];

lld dp (int i, bool one, bool pos_certa){
	if (!s[i]) return 1;
	
	lld &ans = memo[i][one][pos_certa];
	if (ans != -1) return ans;
	ans = 0;
	
	for (int j = 0; j <= 9; j++){
		if (j+'0' > s[i] && pos_certa) break;
		if (j == 3 && one) continue;
		if (j == 4) continue;
		ans += dp(i+1, j == 1, pos_certa && j+'0' == s[i]);
	}
	return ans;
	
}


int main (){
	llu n;
	while (scanf ("%llu", &n) == 1){
		llu inicio = 0, fim = 10000000000000000000llu;;
		llu meio;
		while (inicio < fim){
			meio = ((fim-inicio)/2llu) + inicio;
			memset (memo, -1, sizeof(memo));
			sprintf (s, "%llu", meio);
			if (dp(0,0,1) < n+1){ inicio = meio+1;}
			else{ fim = meio;}
		}
		printf ("%llu\n", inicio);
	}
	return 0;
}
