#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)

int main(){

	char c;
	string s;

	cin >> c >> s;

	while (c != '0'){
		bool zero = true;

		for (int i = 0; i < s.size(); i++){
			if (s[i] == c) continue;
			if (zero){
				if (s[i] != '0'){
					zero = false;
					cout << s[i];
				}
			}
			else {
				cout << s[i];
			}
		}

		if (zero) cout << "0";
		cout << endl;

		cin >> c >> s;		
	}

	return 0;
}