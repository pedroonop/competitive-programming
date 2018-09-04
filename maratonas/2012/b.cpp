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
#define dd pair<double, double>
#define linha pair<dd, dd>

dd operator-(const dd &a, const dd &b){
	return dd(a.x - b.x, a.y - b.y);
}

double dot(dd a, dd b){
	return a.x * b.x + a.y * b.y;
}

double cross(dd a, dd b){
	return a.x * b.y - a.y * b.x;
}

double dist(dd a, dd b){
	dd c = a - b;
	return sqrt(c.x * c.x + c.y * c.y);
}

double dist(dd ponto, linha reta){
	double crs = cross(ponto - reta.ff, reta.ss - reta.ff);
	return fabs(crs / dist(reta.ff, reta.ss));
}

int main(){

	double l, h;
	int n;

	while (scanf("%d", &n) == 1){
		scanf("%lf %lf", &l, &h);
		double a, b, c;
		linha vet[1001];
		go (i, n){
			scanf("%lf %lf %lf", &a, &b, &c);
			if (i % 2)
				vet[i].ff.x = l;
			else
				vet[i].ff.x = 0;
			vet[i].ff.y = a;
			vet[i].ss.x = b;
			vet[i].ss.y = c;
		}

		double minimo = l - vet[0].ss.x;

		for (int i = 1; i < n; i++){
			if (dot(vet[i].ff - vet[i].ss, vet[i - 1].ss - vet[i].ss) < 0) minimo = min(minimo, dist(vet[i - 1].ss, vet[i].ss));
			else minimo = min(minimo, dist(vet[i - 1].ss, vet[i]));

			if (i % 2 == 0) minimo = min(minimo, l - vet[i].ss.x);
			else minimo = min(minimo, vet[i].ss.x);
		}

		printf("%.2lf\n", minimo);		
	}


	return 0;
}