#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 100000
#define dd pair<double, double>

#define ddd pair<double, dd>
#define x first
#define y second.first
#define z second.second

#define linha pair<ddd, ddd>
#define plano pair<ddd, linha>
#define ff first
#define ss second.first
#define tt second.second
#define EPS 0.000001

#define min_(a, b, c) min(a, min(b, c))

ddd operator+(ddd a, ddd b){
	return ddd(a.x + b.x, dd(a.y + b.y, a.z + b.z));
}

ddd operator-(ddd a, ddd b){
	return ddd(a.x - b.x, dd(a.y - b.y, a.z - b.z));
}

ddd operator*(double n, ddd p){
	return ddd(n * p.x, dd(n * p.y, n * p.z));
}

ddd operator/(ddd p, double n){
	return ddd(p.x / n, dd(p.y / n, p.z / n));
}

ddd cross(ddd a, ddd b){
	return ddd(a.y * b.z - a.z * b.y, dd (a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

double dot(ddd a, ddd b){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

double module(ddd a){
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

double dist(ddd a, ddd b){
	return module(b - a);
}

double dist(ddd a, linha l){
	double crs = module(cross(a - l.first, l.second - l.first));
	return fabs(crs / dist(l.first, l.second));
}

double dist(ddd a, plano p){
	ddd N = cross(p.ff - p.ss, p.ss - p.tt);
	return abs(dot(p.ff - a, N) / module(N));
}

ddd oposto(ddd a, ddd b, ddd c){
	double m_bd = dot(a - b, c - b) / module(c - b);
	return (m_bd * ((c - b) / module(c - b))) + b;
}

bool pxp(ddd point, plano p){
	ddd a = p.ff, b = p.ss, c = p.tt;
	ddd a_  = oposto(a, b, c), b_ = oposto(b, a, c), c_ = oposto(c, a, b);
	if (point == ddd(8, dd(-3, -10)) && p.ff == ddd(10, dd(-4, 8)) && p.tt == ddd(-8, dd(2, 1))){
		printf("%lf %lf %lf\n", b_.x, b_.y, b_.z);
		printf("%lf %lf %lf\n", (b_ - b).x, (b_ - b).y, (b_ - b).z);
		printf("%lf %lf %lf\n", (b_ - point).x, (b_ - point).y, (b_ - point).z);
		printf("aaa: %lf\n", dot(b_ - b, b_ - point));
	}
	return dot(a_ - a, a_ - point) >= 0 && dot(b_ - b, b_ - point) >= 0 && dot(c_ - c, c_ - point) >= 0;
}

bool pxl(ddd point, linha l){
	ddd a = l.first, b = l.second;
	return dot(a - b, a - point) >= 0 && dot(b - a, b - point) >= 0;
}

double real_dist(ddd point, plano p){
	double minimo = INF;
	if (pxp(point, p)) minimo = min(minimo, dist(point, p));

	linha a = linha(p.ff, p.ss), b = linha(p.ff, p.tt), c = linha(p.ss, p.tt);
	bool a_ = pxl(point, a), b_ = pxl(point, b), c_ = pxl(point, c);

	printf("pxp: %lf\n", dist(point, p));
	printf("pxl: %lf %lf %lf\n", dist(point, a), dist(point, b), dist(point, c));
	printf("pxx: %lf %lf %lf\n", dist(point, p.ff), dist(point, p.ss), dist(point, p.tt));

	if (a_) minimo = min(minimo, dist(point, a));
	if (b_) minimo = min(minimo, dist(point, b));
	if (c_) minimo = min(minimo, dist(point, c));
	minimo = min(minimo, dist(point, p.ff));
	minimo = min(minimo, dist(point, p.ss));
	minimo = min(minimo, dist(point, p.tt));
	return minimo;
}

double solve(ddd point, ddd p[4]){
	plano a = plano(p[0], linha(p[1], p[2]));
	plano b = plano(p[0], linha(p[1], p[3]));
	plano c = plano(p[0], linha(p[2], p[3]));
	plano d = plano(p[1], linha(p[2], p[3]));

	double minimo = INF;
	minimo = min(minimo, real_dist(point, a));
	minimo = min(minimo, real_dist(point, b));
	minimo = min(minimo, real_dist(point, c));
	minimo = min(minimo, real_dist(point, d));
	return minimo;
}

ddd read_point(){
	ddd p;
	scanf("%lf %lf %lf", &p.x, &p.y, &p.z);
	return p;
}

int main(){

	int n;
	scanf("%d", &n);

	while (n--){
		ddd reb[4];
		go (i, 4){
			reb[i] = read_point();
		}

		ddd imp[4];
		go (i, 4){
			imp[i] = read_point();
		}

		double minimo = INF;

		go (i, 4){
			minimo = min(minimo, solve(reb[i], imp));
			minimo = min(minimo, solve(imp[i], reb));
		}

		printf("%.2lf\n", minimo);		
	}


/*	plano p;
	p.ff.x = 0; p.ff.y = 0; p.ff.z = 0;
	p.ss.x = 1; p.ss.y = 0; p.ss.z = 0;
	p.tt.x = 1; p.tt.y = 1; p.tt.z = 0;

	ddd d;
	d.x = 0; d.y = 0.5; d.z = 0;
*/
	return 0;
}