#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)

llu fat(int n, int k){
	if (n <= 0) return 1;
	return n * fat(n - k, k);
}

int main(){

	int t;

	cin >> t;

	while (t--){
		int n;
		string f;

		cin >> n >> f;

		int k = f.size();

		cout << fat(n, k) << endl;		
	}

	return 0;
}