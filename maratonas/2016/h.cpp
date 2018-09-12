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

bool pal(string rs, int i, int j){
	if (i >= j) return true;
	if (rs[i] == rs[j]){
		return pal(rs, i + 1, j - 1);
	}
	return false;
}

int main(){
	fastcin;
	string rs;
	string p_rs;

	cin >> rs;

	for (int i = 0; i < (int) rs.size(); i++){
		if (rs[i] == 'a' || rs[i] == 'e' || rs[i] == 'i' || rs[i] == 'o' || rs[i] == 'u'){
			p_rs += rs[i];
		}
	}

	pal(p_rs, 0, (int) p_rs.size() - 1) ? printf("S\n") : printf("N\n");

	return 0;
}