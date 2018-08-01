#include <bits/stdc++.h>
using namespace std;
int vetor[111];
set <int> s;
int main (){
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		for (int j = a; j <= b; j++){
			vetor[j] = 1;
		}
	}
	int cont = 0;
	for (int i = 1; i <= m; i++){
		if (!vetor[i]) cont++;
	}
	printf ("%d\n", cont);
	for (int i = 1; i <= m; i++){
		if (!vetor[i]) printf ("%d ", i);
	}
	printf ("\n");
	return 0;
}
