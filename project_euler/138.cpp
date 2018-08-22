#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

bool is_quadrado_perfeito(llu n, llu num){
	return num * num == n;
}

int main(){


	llu b = 16;
	int cont = 0;
	llu sum = 0;
	while (cont < 20){
		llu op1 = (b - 1) * (b - 1) + (b / 2) * (b / 2);
		llu op2 = (b + 1) * (b + 1) + (b / 2) * (b / 2);
		llu s1 = sqrt(op1), s2 = sqrt(op2);
		if (is_quadrado_perfeito(op1, s1)){
			cont++;
			cout << cont << " " << s1 << endl;
			sum += s1;
		}
		else if (is_quadrado_perfeito(op2, s2)){
			cont++;
			cout << cont << " " << s2 << endl;
			sum += s2;
		}
		b += 2;
	}

	printf("%llu\n", sum);

	return 0;
}