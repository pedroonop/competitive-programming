#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ff pair<long double, long double>
#define x first
#define y second
#define EPS 0.0001

int main(){

	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	ii ponto[101];
	ff angulo[101];

	for (int i = 1; i <= n; i++){
		scanf("%d %d", &ponto[i].x, &ponto[i].y);
		angulo[i].x = ((long double)ponto[i].y) / (ponto[i].x - a);
		angulo[i].y = ((long double)ponto[i].y) / (b - ponto[i].x);
	}

	sort(angulo + 1, angulo + n + 1);

	int M[101];
	M[0] = 0;
	for (int i = 1; i <= n; i++){
		M[i] = 1;
		for (int j = i - 1; j > 0; j--){
			if (angulo[i].x > angulo[j].x - EPS && angulo[i].y > angulo[j].y - EPS){
				M[i] = max(M[i], M[j] + 1);
			}
		}
	}

	int maior = 0;
	for (int i = 1; i <= n; i++){
		maior = max(maior, M[i]);
	}

	printf("%d\n", maior);

	if (false)
		for (int i = 1; i <= n; i++)
			cout << angulo[i].x << " " << angulo[i].y << endl;

	return 0;
}