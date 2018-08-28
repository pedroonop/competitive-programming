#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

llu base36_2_base10(string base){
	llu r = 0;
	for (int i = 0; i < base.size(); i++){
		char c = base[i];
		r = r * 36;
		if ('0' <= c && c <= '9') r = r +  (c - '0');
		else r = r + (c - 'A') + 10;
	}
	return r;
}

string base10_2_base36(llu base){
	string r;
	while (base > 0){
		llu aux = base % 36;
		if (aux < 10) r += (char) aux + '0';
		else r += (char) (aux - 10) + 'A';
		base = base / 36;
	}
	string r_;
	for (int i = r.size() - 1; i >= 0; i--){
		r_ += r[i];
	}
	return r_;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	while (a != "0"){
		llu r = base36_2_base10(a) + base36_2_base10(b);

		cout << base10_2_base36(r) << endl;

		cin >> a >> b;	
	}


	return 0;
}