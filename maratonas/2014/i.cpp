#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<lld, lld>
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

lld gcdExtended(lld a, lld b, lld *x, lld *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    lld x1, y1; // To store results of recursive call 
    lld gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

lld exp(lld a, lld n, lld mod){
	if (n == 0) return 1;
	if (n == 1) return a % mod;
	lld m = exp(a, n / 2, mod);
	if (n % 2 == 0) return (m * m) % mod;
	return (((m * m) % mod) * a ) % mod;
}

int main(){

	lld n, e, c;
	scanf("%lld %lld %lld", &n, &e, &c);

	lld a = 1, b = n;

	for (lld i = 2; i * i <= n; i++){
		if (n % i == 0){
			a = i;
			b = (n / i);
		}
	}

	lld totient = (a - 1) * (b - 1);

	lld x, y;

	gcdExtended(e, totient, &x, &y);

	if (x < 0) x += totient;

	lld d = x;

	printf("%lld\n", exp(c, d, n));

	return 0;
}