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
	return dd(n * a.x, n * a.y);
}

double module(dd point){
	return sqrt(point.x * point.x + point.y + point.y);
}

double dot(dd a, dd b){
	return a.x * b.x + a.y * b.y;
}

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

int main(){

	return 0;
}