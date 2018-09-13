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
#define line pair<dd, dd>

dd operator+(dd a, dd b){
	return dd(a.x + b.x, a.y + b.y);
}

dd operator-(dd a, dd b){
	return dd(a.x - b.x, a.y - b.y);
}

dd operator*(double n, dd point){
	return dd(n * point.x, n * point.y);
}

dd operator/(dd point, double n){
	return dd(point.x / n, point.y / n);
}

double module(dd point){
	return sqrt(point.x * point.x + point.y + point.y);
}

//Supondo a e b não nulos, temos que o produto escalar deles vai ser
//menor que zero se eles tiverem um ângulo maior que 90º entre eles,
//igual a 0 se forem perpendiculares e maior que zero se formarem um ângulo agudo.
//dot(a, b) = cos(ab) * module(a) * module(b)
double dot(dd a, dd b){
	return a.x * b.x + a.y * b.y;
}

//O produto vetorial nos dá a área do paralelogramo com lados a e b (com sinal)
//e nos permite saber se o ângulo entre a e b é menor que 180 (se a área for menor que 0),]
//igual a 180 (se a área for igual a 0, no caso os vetores são paralelos), ou maior que 180
//(se a área for maior que 180).
//dot(a, b) = sin(ab) * module(a) * module(b)
double cross(dd a, dd b){
	return a.x * b.y - a.y * b.x;
}

double dist(dd a, dd b){
	return module(a - b);
}

double dist(dd a, line l){
	double crs = cross(a - l.ff, l.ss - l.ff);
	return fabs(crs / dist(l.ff, l.ss));
}

double area(vector <dd> p){
	double ret = 0;
	for(int i = 2; i < p.size(); ++i){
	ret += cross(p[i] - p[0], p[i - 1] - p[0])/2;
	}
	return abs(ret);
}

//Toma 3 números e retorna se eles formam um ângulo convexo ou côncavo.
bool ccw(dd a, dd b, dd c){
	return cross(b - a, c - b) > 0;
}

// convex hull - modifique como necessario
void convex_hull(dd p[], dd st[], int n) {
	sort(p, p + n);
	int sn = 0;
	for(int i = 0; i < n; i++) {
		while(sn >= 2 && ccw(st[sn - 2], st[sn - 1], p[i]) > 0)
			sn--;
		st[sn++] = p[i];
	}
	int k = sn;
	for(int i = n - 2; i >= 0; i--) {
		while(sn > k && ccw(st[sn - 2], st[sn - 1], p[i]))
			sn--;
		st[sn++] = p[i];
	}
	sn--;
	// st[0..sn-1] agora tem o convex hull dos pontos p
}

int main(){

	return 0;
}