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
	return dot(a_ - a, a_ - point) >= 0 && dot(b_ - b, b_ - point) >= 0 && dot(c_ - c, c_ - point) >= 0;
}

bool pxl(ddd point, linha l){
	ddd a = l.first, b = l.second;
	return dot(a - b, a - point) >= 0 && dot(b - a, b - point) >= 0;
}

int main(){

	return 0;
}