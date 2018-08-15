#include <bits/stdc++.h>

using namespace std;

int main(){

	string number;
	cin >> number;

	int last = number.back() - '0';

	if (last % 2 == 0){
		cout << "S" << endl;
	}
	else{
		cout << "N" << endl;
	}

	int cont = 0;
	for (char c : number){
		cont = (cont + (int)(c - '0')) % 3;
	}
	if (cont == 0){
		cout << "S" << endl;
	}
	else{
		cout << "N" << endl;
	}

	if (last == 0 || last == 5){
		cout << "S" << endl;
	}
	else{
		cout << "N" << endl;
	}

	return 0;
}