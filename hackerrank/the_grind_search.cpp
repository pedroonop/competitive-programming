#include <bits/stdc++.h>
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
#define MAX_N 1001
using namespace std;

bitset<1001> mb[1001][1001];


char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P
//map <int, vi> ma;
vii v;
int aux[1001];
void kmpPreprocess(string P) { // call this before calling kmpSearch()
	m = P.size();
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above



bool kmpSearch(string T, string P, int l, int c, int p) { // this is similar as kmpPreprocess(), but on string T
	int i = 0, j = 0; // starting values
	n = T.size(); m = P.size();
	while (i < n) { // search through string T
	    while (j >= 0 && T[i] != P[j]){ j = b[j]; } // if different, reset j using b
	    i++; j++; // if same, advance both pointers
	    if (j == m) { // a match found when j == m
	    	//printf("j = %d\n",j );
	    //  if (p == 1)
		  //printf("P is found at index %d in T   l = %d  c = %d  p = %d\n", i - j, l, i-j, p);
	      //cout << P << endl;
	      mb[l][i-j][p] = 1;
	      if (p == 0){
			  v.push_back(ii(l,i-j));
			//  printf("add i = %d  j = %d\n", v[0].ff, v[0].ss);
		  }
		  if (p == 1) aux[l] = i-j;
	      j = b[j]; // prepare j for the next possible match
	      //return true;
	      
		} 
	}
	return false; 
}


int main (){
	ms(aux,-1);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, p, pp, t;
	cin >> t;
	while (t--){
		ms(mb,0);
		v.clear();
		cin >> n >> m;
		string grid[n];
		go(i,n){
			cin >> grid[i];
		}
		cin >> p >> pp;
		string padrao[p];
		go(i,p){
			cin >> padrao[i];
		}
		
		go(i,p){
			kmpPreprocess(padrao[i]);
			go(j,n){
				kmpSearch(grid[j], padrao[i], j, i, i);
			}
		}
		
		//printf("tam = %lu  i = %d  j = %d\n", v.size(), v[0].ff, v[0].ss);
		bool flag = false;
		go(i,v.size()){
			//printf("i = %d\n", i);
			if (flag) break;
			int l = v[i].ff, c = v[i].ss;
			int pad = 1;
			for (int j = l+1; j < n; j++){
				//printf("pad = %d\n", pad);
				if (pad == p){
					//printf("entrou\n");
					flag = true;
					break;
				}
				if (!mb[j][c][pad]){
					//printf("saiu!!\nj = %d  c = %d pad = %d\n", j, c, pad);
					//printf("%d\n", aux[j]);
					break;
				}
				pad++;
			}
			if (pad == p) flag = true;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
