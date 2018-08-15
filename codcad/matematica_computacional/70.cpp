#include <bits/stdc++.h>

using namespace std;

int main(){

	string number;
	cin >> number;

	if (number.size() < 2){

		int n = number.front() - '0';

		if (n % 4 == 0){
			cout << "S" << endl;
		}
		else{
			cout << "N" << endl;
		}
		if (n % 9 == 0){
			cout << "S" << endl;
		}
		else{
			cout << "N" << endl;
		}
		if (n % 25 == 0){
			cout << "S" << endl;
		}
		else{
			cout << "N" << endl;
		}

		return 0;
	}

	int last = 10 * (number[number.size() - 2] - '0') + (number[number.size() - 1] - '0');

	if (last % 4 == 0){
		cout << "S" << endl;
	}
	else{
		cout << "N" << endl;
	}

	int cont = 0;
	for (char c : number){
		cont = (cont + (int)(c - '0')) % 9;
	}
	if (cont == 0){
		cout << "S" << endl;
	}
	else{
		cout << "N" << endl;
	}

	if (last == 0 || last == 25 || last == 50 || last == 75){
		cout << "S" << endl;
	}
	else{
		cout << "N" << endl;
	}

	return 0;
}