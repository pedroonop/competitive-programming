#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 305100
#define vi vector <int>
#define ii pair <int,int>
#define iii pair <ii,int>
#define vii vector<ii>
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
#define lld long long int
#define iic pair <ii, char>
using namespace std;

int g(string x){
	int cont = 0;
	while (x.size() > 1){
		cont = 0;
		for (char c : x){
			cont += c-'0';
		}
		x = to_string(cont);
	}
	return stoi(x);
}

int f (int z){
	string x = to_string(z);
	int cont;
	while (x.size() > 1){
		cont = 0;
		for (char c : x){
			cont += c-'0';
		}
		x = to_string(cont);
	}
	return stoi(x);
}

int poww (int base, int exp){
	if (exp == 0) return 1;
	if (exp == 1) return base;
	int x = poww(base,exp/2);
	if (exp & 1){
		return f(base) * f(x) * f(x);
	}
	return f(f(x) * f(x));
}


int main (){
	string base, exp;
	cin >> base;
	cin >> exp;
	int x = g(base);
	int ans = 1;
	int temp = 1;
	for (int i = exp.size()-1, w = 1; i >= 0; i--, w++){
		x = poww(x,temp);
		ans *= poww(x,exp[i]-'0');
		ans = f(ans);
		temp *= 10;
	}
	printf ("%d\n", ans);
	return 0;
}
