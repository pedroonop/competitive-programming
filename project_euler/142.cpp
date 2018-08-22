#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

bool is_quadrado_perfeito[1000000001];

int main(){

	for (int i = 1; i * i <= 1000000000; i++){
		is_quadrado_perfeito[i * i] = true;
	}

	llu x_mais_y;
	llu cont = 1;
	for (x_mais_y = 1; ; x_mais_y += (cont += 2)){
		printf("%llu\n", x_mais_y);
		for (llu x = x_mais_y - 1; x >= 3; x--){
			llu y = x_mais_y - x;
			if (y >= x) break;
			if (is_quadrado_perfeito[x - y]){
				for (llu z = 1; z < y; z++){
					if (is_quadrado_perfeito[x + z] &&
						is_quadrado_perfeito[x - z] &&
						is_quadrado_perfeito[y + z] &&
						is_quadrado_perfeito[y - z]){
						printf("%llu\n", x + y + z);
						return 0;
					}
				}
			}
		}
	}

	return 0;
}