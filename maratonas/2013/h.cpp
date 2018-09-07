#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<llu, llu>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (llu i = 0; i < (llu)n; i++)
#define vi vector <llu>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>

typedef struct{
	llu m[2][2];
	llu* operator[](llu i){
		return m[i];
	}
}matrix;

matrix mult_m(matrix a, matrix b, llu m){
	matrix c;
	c[0][0] = ((a[0][0] * b[0][0]) % m + (a[0][1] * b[1][0]) % m) % m;
	c[0][1] = ((a[0][0] * b[0][1]) % m + (a[0][1] * b[1][1]) % m) % m;
	c[1][0] = ((a[1][0] * b[0][0]) % m + (a[1][1] * b[1][0]) % m) % m;
	c[1][1] = ((a[1][0] * b[0][1]) % m + (a[1][1] * b[1][1]) % m) % m;
	return c;
}

matrix exp_m(matrix a, llu n, llu m){
	if (n == 1) return a;
	llu k = n / 2;
	matrix aux = exp_m(a, k, m);
	if (n % 2 == 0) return mult_m(aux, aux, m);
	return mult_m(a, mult_m(aux, aux, m), m);
}

pair<llu, llu> mxv(matrix a, pair<llu, llu> v, llu m){
	return make_pair((a[0][0] * v.first + a[0][1] * v.second) % m, (a[1][0] * v.first + a[1][1] * v.second) % m);
}

int main(){

	matrix m;

	llu n, k, l;

	while (scanf("%llu %llu %llu", &n, &k, &l) == 3){
		n = n / 5;

		k = k % 1000000;
		l = l % 1000000;

		m[0][0] = k;
		m[0][1] = l;
		m[1][0] = 1;
		m[1][1] = 0;

		if (n == 1){
			printf("%.6llu\n", k);
			continue;
		}
		if (n == 2){
			printf("%.6llu\n", (k * k + l) % 1000000);
			continue;
		}

		matrix r = exp_m(m, n - 2, 1000000);

		pair<llu, llu> f = mxv(r, make_pair(k * k + l, k), 1000000);

		printf("%.6llu\n", f.first);		
	}

	return 0;
}