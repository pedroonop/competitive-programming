#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define d 26
#define q 1000000007
using namespace std;

#define MAX_N 100010
string origem, aux;

map <int, string> hash_ruins;
map <int, string> hash_bons;
int hash_origem = 0;

int main(){
	char x;
	x = getchar();
	int n;
	while (x != '\n' && x != '\0'){
	  //printf ("%c", x);
	  if (x >= 'A' && x <= 'Z') x = x - 'A' + 'a';
	  origem += x;
	  hash_origem = (hash_origem*d + x)%q;
	  x = getchar();
	}
	//printf ("\n");
	scanf ("%d\n", &n);
	
	x = getchar();
	//printf ("x = %c", x);
	int hash = 0;
	while (x != '\n' && x != '\0'){
		//printf ("%c", x);
		if (x == ' '){
			hash_bons[hash] = aux;
			aux = "";
			hash = 0;
			x = getchar();
			continue;
		}
		if (x >= 'A' && x <= 'Z') x = x - 'A' + 'a';
		aux += x;
		hash = (hash*d + x)%q;
		x = getchar();
	}
	hash_bons[hash] = aux;
	aux = "";
	hash = 0;
	//printf ("\n");
	scanf ("%d\n", &n);
	x = getchar();
	hash = 0;
	while (x != '\n' && x != '\0'){
		//printf ("%c", x);
		if (x == ' '){
			hash_ruins[hash] = aux;
			aux = "";
			hash = 0;
			x = getchar();
			continue;
		}
		if (x >= 'A' && x <= 'Z') x = x - 'A' + 'a';
		aux += x;
		hash = (hash*d + x)%q;
		x = getchar();
	}
	hash_ruins[hash] = aux;
	aux = "";
	hash = 0;
	
	scanf ("%d\n", &n);
	int posi = 0, nega = 0, neutro = 0;
	go(i,n){
		bool pode = false;
		int mais = 0, menos = 0;
		x = getchar();
		hash = 0;
		while (x != '\n' && x != '\0'){
			//printf ("%c", x);
			if (x == ' '){
				if (hash == hash_origem)
					if (origem == aux){
						cout << origem << " igual a origem\n";
						pode = true;
					}
				if (hash_bons.find(hash) != hash_bons.end())
					if (hash_bons[hash] == aux){
						mais++;
					}
				if (hash_ruins.find(hash) != hash_ruins.end())
					if (hash_ruins[hash] == aux){
						menos++;
					}
				
				aux = "";
				hash = 0;
				x = getchar();
				continue;
			}
			if (x >= 'A' && x <= 'Z') x = x - 'A' + 'a';
			aux += x;
			hash = (hash*d + x)%q;
			x = getchar();
		}
		if (pode){
			if (menos == mais) neutro++;
			else if (menos > mais) nega++;
			else posi++;
		}
	}
	printf ("%d %d %d\n", posi, neutro, nega);
	
	return 0;
}
