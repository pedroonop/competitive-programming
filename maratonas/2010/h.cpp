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

map<string, int> mapa;
int v[100001];
int c[10001];

int b[100001];

void kmpPreprocess(int P[], int t) { // call this before calling kmpSearch()
	int m = t;
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

bool kmpSearch(int T[], int P[], int n, int m, int var) { // this is similar as kmpPreprocess(), but on string T
	int i = 0, j = 0; // starting values
	while (i < n) { // search through string T
	    while (j >= 0 && ((T[i] + var) % 12) != P[j]){ j = b[j]; } // if different, reset j using b
	    i++; j++; // if same, advance both pointers
	    if (j == m) { // a match found when j == m
	    	//printf("j = %d\n",j );
	      //printf("P is found at index %d in T\n", i - j);
	      j = b[j]; // prepare j for the next possible match
	      return true;
		} 
	}
	return false; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	mapa["A"] = 0;
	mapa["A#"] = 1;
	mapa["Bb"] = 1;
	mapa["B"] = 2;
	mapa["Cb"] = 2;
	mapa["B#"] = 3;
	mapa["C"] = 3;
	mapa["C#"] = 4;
	mapa["Db"] = 4;
	mapa["D"] = 5;
	mapa["D#"] = 6;
	mapa["Eb"] = 6;
	mapa["E"] = 7;
	mapa["Fb"] = 7;
	mapa["E#"] = 8;
	mapa["F"] = 8;
	mapa["F#"] = 9;
	mapa["Gb"] = 9;
	mapa["G"] = 10;
	mapa["G#"] = 11;
	mapa["Ab"] = 11;

	int m, t;

	cin >> m >> t;

	while (m != 0){

		go(i, m){
			string aux;
			cin >> aux;
			v[i] = mapa[aux];
		}

		go(i, t){
			string aux;
			cin >> aux;
			c[i] = mapa[aux];		
		}

		kmpPreprocess(c, t);

		bool flag = true;

		for (int i = 0; i < 12; i++){
			if (kmpSearch(v, c, m, t, i)){
				printf("S\n");
				flag = false;
				break;
			}
		}
		if (flag) printf("N\n");		

		cin >> m >> t;
		
	}

	return 0;
}