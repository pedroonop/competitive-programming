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
#define EPS 0.00001

ii write_letter(char c){
	switch (c){
		case ('a'): return ii(2, 1);
		case ('b'): return ii(2, 2);
		case ('c'): return ii(2, 3);
		case ('d'): return ii(3, 1);
		case ('e'): return ii(3, 2);
		case ('f'): return ii(3, 3);
		case ('g'): return ii(4, 1);
		case ('h'): return ii(4, 2);
		case ('i'): return ii(4, 3);
		case ('j'): return ii(5, 1);
		case ('k'): return ii(5, 2);
		case ('l'): return ii(5, 3);
		case ('m'): return ii(6, 1);
		case ('n'): return ii(6, 2);
		case ('o'): return ii(6, 3);
		case ('p'): return ii(7, 1);
		case ('q'): return ii(7, 2);
		case ('r'): return ii(7, 3);
		case ('s'): return ii(7, 4);
		case ('t'): return ii(8, 1);
		case ('u'): return ii(8, 2);
		case ('v'): return ii(8, 3);
		case ('w'): return ii(9, 1);
		case ('x'): return ii(9, 2);
		case ('y'): return ii(9, 3);
		case ('z'): return ii(9, 4);
		default: return ii(0, 1);
	}
}

vii press(int n, string s){
	vii result;
	result.pb(write_letter(s[0]));
	for (int i = 1; i < n; i++){
		ii aux = write_letter(s[i]);
		if (aux.ff == result.back().ff) result.pb(ii(10, 1));
		result.pb(aux);
	}
	return result;
}

double dt[][11] = {
	{0.000000, 3.162278, 3.000000, 3.162278, 2.236068, 2.000000, 2.236068, 1.414214, 1.000000, 1.414214, 1.000000}, 
	{3.162278, 0.000000, 1.000000, 2.000000, 1.000000, 1.414214, 2.236068, 2.000000, 2.236068, 2.828427, 3.605551}, 
	{3.000000, 1.000000, 0.000000, 1.000000, 1.414214, 1.000000, 1.414214, 2.236068, 2.000000, 2.236068, 3.162278}, 
	{3.162278, 2.000000, 1.000000, 0.000000, 2.236068, 1.414214, 1.000000, 2.828427, 2.236068, 2.000000, 3.000000}, 
	{2.236068, 1.000000, 1.414214, 2.236068, 0.000000, 1.000000, 2.000000, 1.000000, 1.414214, 2.236068, 2.828427}, 
	{2.000000, 1.414214, 1.000000, 1.414214, 1.000000, 0.000000, 1.000000, 1.414214, 1.000000, 1.414214, 2.236068}, 
	{2.236068, 2.236068, 1.414214, 1.000000, 2.000000, 1.000000, 0.000000, 2.236068, 1.414214, 1.000000, 2.000000}, 
	{1.414214, 2.000000, 2.236068, 2.828427, 1.000000, 1.414214, 2.236068, 0.000000, 1.000000, 2.000000, 2.236068}, 
	{1.000000, 2.236068, 2.000000, 2.236068, 1.414214, 1.000000, 1.414214, 1.000000, 0.000000, 1.000000, 1.414214}, 
	{1.414214, 2.828427, 2.236068, 2.000000, 2.236068, 1.414214, 1.000000, 2.000000, 1.000000, 0.000000, 1.000000}, 
	{1.000000, 3.605551, 3.162278, 3.000000, 2.828427, 2.236068, 2.000000, 2.236068, 1.414214, 1.000000, 0.000000}
};

double M[1410][11][11];

double total_dist(vii p){
	for (int menor = 0; menor < 10; menor++){
		for (int maior = menor + 1; maior <= 10; maior++){
			M[p.size()][menor][maior] = 0;
		}
	}
	for (int i = p.size() - 1; i >= 0; i--){
		for (int menor = 0; menor < 10; menor++){
			for (int maior = menor + 1; maior <= 10; maior++){
				if (p[i].ff == menor || p[i].ff == maior){
					M[i][menor][maior] = M[i + 1][menor][maior];
				}
				else{
					M[i][menor][maior] = min(
						dt[menor][p[i].ff] + M[i + 1][min(p[i].ff, maior)][max(p[i].ff, maior)],
						dt[maior][p[i].ff] + M[i + 1][min(p[i].ff, menor)][max(p[i].ff, menor)]
					);
				}
			}
		}
	}
	return M[0][4][6];
}

int main(){
	fastcin;

	string s;
	while (getline(cin, s)){
		int n = s.size();

		vii p = press(n, s);

		double d = total_dist(p);
		d = d / 30;

		int cont = 0;

		for (int i = 0; i < (int)p.size(); i++){
			cont += p[i].ss;
		}

		d += 0.2 * cont;
		printf("%.2lf\n", d);
	}

	return 0;
}