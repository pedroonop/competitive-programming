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
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 1000

int main(){

	string s;
	cin >> s;

	bool M[MAXN + 1][MAXN + 1];

	ms(M, false);

	go (i, s.size()){
		M[i][i] = true;
	}

	go (i, s.size() - 1){
		M[i][i + 1] = s[i] == s[i + 1];
	}

	for (int i = s.size() - 2; i >= 0; i--){
		for (int j = i + 2; j < s.size(); j++){
			M[i][j] = (s[i] == s[j] && M[i + 1][j - 1]);
		}
	}

	go (i, s.size()){
		go (j, s.size()){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}