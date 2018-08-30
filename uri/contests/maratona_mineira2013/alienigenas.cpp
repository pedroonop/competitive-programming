#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<lld, lld>
#define pb(x) push_back(x)

int main(){

	lld n;

	scanf("%lld", &n);

	while (n != 0){
		set<vector<lld> > conj;
		for (lld i = 0; i < n; i++){
			string s;
			cin >> s;
			vector<lld> v;
			v.resize(20, 0);
			for (char c : s){
				v[c - 'A']++;
			}
			conj.insert(v);
		}

		printf("%lld\n", (lld)conj.size());
		scanf("%lld", &n);		
	}

	return 0;
}
