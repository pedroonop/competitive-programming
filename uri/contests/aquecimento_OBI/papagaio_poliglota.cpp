#include <bits/stdc++.h>
using namespace std;

int main (){
	string s;
	while (getline(cin, s)){
		if (s == "esquerda") printf ("ingles\n");
		else if (s == "direita") printf ("frances\n");
		else if (s == "nenhuma") printf ("portugues\n");
		else if (s == "as duas") printf ("caiu\n");
	}
	return 0;
}
