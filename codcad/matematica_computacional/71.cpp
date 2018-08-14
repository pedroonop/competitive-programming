#include <bits/stdc++.h>

using namespace std;

int main(){

	string number;
	cin >> number;

	long long int cont = 0;
	bool positivo = true;
	for (char c : number){
		int n = c - '0';
		if (positivo){
			cont += n;
		}
		else{
			cont -= n;
		}
		positivo = !positivo;
	}

	if (cont < 0) cont = -cont;

	if (cont % 11 == 0){
		cout << "S" << endl;
	}
	else{
		cout << "N" << endl;
	}

	return 0;
}