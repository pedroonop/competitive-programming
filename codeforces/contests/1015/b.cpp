#include <bits/stdc++.h>
#define mod 1000000007
#define lld long long int
using namespace std;
int n;
string s1;
map <string, int> m;
int testa (string s){
	int cont = 0;
	for (char c : s){
		if (c == '(') cont++;
		if (c == ')') cont--;
		if (cont < 0) return 0;
	}
	return cont == 0;
}

lld add (int a, int b){
	lld result = a + b;
	if (result >= mod) return result-mod;
	return result;
	
}


lld dp (string s){
	//printf ("a = %lu\n", s.size());
	if (m[s]) return 0;
	m[s] = 1;
	if ((int)s.size() == n){return 0;}
	if ((int)s.size() > n) return 0;
	string t = "(";
	t += s;
	string f = "(";
	f = s+f;
	lld ans = 0;
	ans += add(dp(f), dp(t));
	t[0] = ')';
	f[f.size()-1] = ')';
	ans += add(dp(f), dp(t));
	return ans;
}

int main (){
	cin >> n;
	cin >> s1;
	n = 2*n;
	printf ("%lld\n", dp(s1));
	n = 2*n;
	return 0;
}
