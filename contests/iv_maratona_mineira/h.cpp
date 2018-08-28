#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define ff pair<float, float>

ff subtrair(ff a, ff b){
	return ff(a.x - b.x, a.y - b.y);
}

float vetorial(ff a, ff b){
	return a.x * b.y - a.y * b.x;
}

float ccw(ff a, ff b, ff c){
	return vetorial(subtrair(b, a), subtrair(c, b));
}

bool cruza(ff a, ff b, ff c, ff d){
	return ccw(a, b, c) * ccw(a, b, d) < 0;
}

float modulo(ff a){
	return sqrt(a.x * a.x + a.y * a.y);
}

vector<vector<pair<int, float> > > g;

int main(){

	ff origem, destino;

	scanf("%f %f %f %f", &origem.x, &origem.y, &destino.x, &destino.y);

	int n;
	scanf("%d", &n);

	vector<pair<ff, ff> > parede;
	parede.resize(n);

	for (int i = 0; i < n; i++){
		scanf("%f %f", &parede[i].x.x, &parede[i].x.y, &parede[i].y.x, &parede[i].y.y);
	}

	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			for (int k = 0; k < n; k++){
				//x to x
				if (!cruza(parede[i].x, parede[j].x, parede[k].x, parede[k].y)){
					
				}

			}

		}
	}

	return 0;
}