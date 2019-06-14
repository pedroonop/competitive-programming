#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<lld, lld>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (lld i = 0; i < (lld)(n); i++)
#define go1(i, n) for (lld i = 1; i <= (lld)(n); i++)
#define vi vector <lld>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define fastcin ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAXP 2750159

lld gDivisor[MAXP + 1];
vi primes;
multiset<lld> b;

int main(){

	for (lld i = 2; i <= MAXP; i++){
		if (gDivisor[i] != 0) continue;
		gDivisor[i] = i;
		primes.pb(i);
		for (lld j = i * i; j <= MAXP; j *= i){
			if (gDivisor[j] == 0) gDivisor[j] = j / i;
		}
	}

	lld n;
	scanf("%lld", &n);
	n = n<<1;

	lld aux;
	go (i, n){
		scanf("%lld", &aux);
		b.insert(aux);
	}

	vi a;
	n = n>>1;

	for (lld i = 2; i <= 200000 && a.size() < n; i++){
		if (gDivisor[i] == i){
			if (b.find(i) != b.end() && b.find(primes[i]) != b.end()){
				a.pb(i);
				b.erase(i);
				b.erase(primes[i]);
			}
		}
		else{
			if (b.find(i) != b.end() && b.find(gDivisor[i]) != b.end()){
				a.pb(i);
				b.erase(i);
				b.erase(gDivisor[i]);
			}
		}
	}

	for (lld x : a){
		printf("%lld\n", x);
	}

	return 0;
}