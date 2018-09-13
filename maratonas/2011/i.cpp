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

dd operator+(dd a, dd b){
	return dd(a.x + b.x, a.y + b.y);
}

dd operator-(const dd &a, const dd &b){
	return dd(a.x - b.x, a.y - b.y);
}

double cross(dd a, dd b){
	return a.x * b.y - a.y * b.x;
}

bool livre(dd a, dd b, int m, linha muros[]){
	dd c = a - b;
	go (i, m){
		
	}
}

int main(){

	int t, m, c;

	scanf("%d %d %d", &t, &m, &c);

	linha muros[51];

	go (i, m){
		scanf("%lf %lf %lf %lf", muros[i].ff.x, muros[i].ff.y, muros[i].ss.x, muros[i].ss.y);
	}

	dd portais[51];

	go (i, c){
		scnaf("%lf %lf", portais[i].x, portais[i].y);
	}



	return 0;
}