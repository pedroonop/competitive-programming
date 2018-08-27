#include <bits/stdc++.h>

#define go(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;

#define MAX_N 100010

//char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess(string P) { // call this before calling kmpSearch()
	m = P.size();
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

bool kmpSearch(string T, string P) { // this is similar as kmpPreprocess(), but on string T
	int i = 0, j = 0; // starting values
	n = T.size(); m = P.size();
	while (i < n) { // search through string T
	    while (j >= 0 && T[i] != P[j]){printf("T = %c   P = %c j = %d\n", T[i], P[j], j); j = b[j]; } // if different, reset j using b
	    i++; j++; // if same, advance both pointers
	    if (j == m) { // a match found when j == m
	    	printf("j = %d\n",j );
	      printf("P is found at index %d in T\n", i - j);
	      j = b[j]; // prepare j for the next possible match
	      return true;
		} 
	} 
}

int main(){
  int x;
  string origem, aux, bons, ruins, linha;
  cin >> aux;
  origem = '$';
  origem += aux;
  cin >> x;
  go(i,origem.size()){
  	if (origem[i] >= 'A' && origem[i] <= 'Z') origem[i] = origem[i] - 'A'+'a';
  }
  bons = '$';
  ruins = '$';
  go(i,x){
  	cin >> aux;
  	go(i,aux.size()){
  		if (aux[i] >= 'A' && aux[i] <= 'Z') aux[i] = aux[i] - 'A'+'a';
  	}
  	bons += aux;
  	//bons += "#";
  }
  cin >> x;
  go(i,x){
  	cin >> aux;
  	go(i,aux.size()){
  		if (aux[i] >= 'A' && aux[i] <= 'Z') aux[i] = aux[i] - 'A'+'a';
  	}
  	ruins += aux;
  	//ruins += "#";
  }
  cin >> x;
  int mais = 0;
  int menos = 0;
  int neutro = 0;
  cout << origem << endl;
  cout << bons << endl;
  cout << ruins << endl;
  go(i,x){
  	getline(cin,linha);
  	getline(cin,linha);
  	bool pode = false;
  	int positivo = 0;
  	int negativo = 0;
  	string aux;
  	for (char c : linha){
  		if (c != ' '){
  			if (c >= 'A' && c <= 'Z') c = c-'A'+'a';
  			aux += c;
  		}
  		else{
    		cout << aux << endl;
  			memset(b, 0, sizeof(b));
  			kmpPreprocess(aux);
  			m = aux.size();
  			n = origem.size();
  			if (kmpSearch (origem, aux)){ pode = true; cout << aux << ":  origem\n";}
  			kmpPreprocess(aux);
  			n = bons.size();
  			if (kmpSearch(bons, aux)){ positivo++;cout << aux << ":  positivo\n";}
  			kmpPreprocess(aux);
  			n = ruins.size();
  			if (kmpSearch(ruins, aux)){ negativo++; cout << aux << ":  negativo\n";}
  			aux = "";
  		}
  	}
  	if (pode){
	  	if (positivo == negativo) neutro++;
	  	else if (positivo > negativo) mais++;
	  	else menos++;
	  }
  }
  printf("%d %d %d\n",mais, menos, neutro);
  return 0;
}
