#include <bits/stdc++.h>

using namespace std;
							// Typedef's  start //
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

							//	Typedef's end //
							//	Define's start //
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

							// Define's end //
ll dp[15][2];
ll pdez[15];
string a;
int n = 0;
ll solve(int i, bool op){
	if(i == n){
		return 0LL;
	}
	if(dp[i][op] != -1LL){
		return dp[i][op];
	}

	int digito = 0;
	if(op == 1){
		digito = 9;
	}
	digito = max(digito,a[i] - '0');
	ll ans = 0;
	bool aux = op;
	while(digito >= 0){
		if((a[i] - '0') > digito)
			aux |= 1;
		if(aux == 1){
			ans += ((((ll)digito)*pdez[n-i-1])%MOD + solve(i+1,aux))%MOD;
					ans %= MOD;
		}else{
			ans += ((((ll)digito) * (atoll(a.substr(i+1).c_str()) + 1))%MOD + solve(i+1,aux))%MOD;
					ans %= MOD;
		}
		digito--;
	}
	return dp[i][op] = ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string b, c;
	pdez[0] = 1LL;
	REP(i,1,15){
		pdez[i] = (pdez[i-1] * 10LL)%MOD;
	}
	while(cin >> b >> c){
		memset(dp,-1,sizeof dp);
		a = b;
		n = a.size();
		ll soma = 0;
		REP(i,0,n){
			soma += (ll)(a[i] - '0');
		}
		ll result_a =solve(0,0);
		a = c;
		n = a.size();
		memset(dp,-1,sizeof dp);
		ll result_b = solve(0,0);
		cout << result_b - result_a + soma << endl;
		
	}

	return 0;
}
