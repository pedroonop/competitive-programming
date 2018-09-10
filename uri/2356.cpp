#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define vvii vector <vii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second
#define dd pair<double, double>
#define ms(v, x) memset(v, x, sizeof(v))
#define MAXN 10001

int main (){
	string s, x;
	while (cin >> s >> x){
		if (strstr(s.c_str(), x.c_str())) printf("Resistente\n");
		else printf("Nao resistente\n");
	}
	return 0;
}
