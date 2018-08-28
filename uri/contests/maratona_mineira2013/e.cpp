#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<lld, lld>
#define pb(x) push_back(x)


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lld n;
	set<vector<lld> > conj;
	string s;
	vector<lld> v;

	cin >> n;

	while (n != 0){
		conj.clear();
		for (lld i = 0; i < n; i++){
			cin >> s;
			v.assign(15, 0);
			for (string::iterator it = s.begin(); it != s.end(); it++){
				v[*it - 'A']++;
			}
			conj.insert(v);
		}

		cout << conj.size() << endl;
		cin >> n;
	}

	return 0;
}