#include <bits/stdc++.h>

using namespace std;

//int last[1000000];
map<char, int> mapa;

int getLast(char c){
/*	if ('0' <= c && c <= '9'){
		return last[c - '0'];
	}
	return last[c - 'a' + 10];*/
	map<char, int>::iterator it = mapa.find(c);
	if (it == mapa.end()) return -1;
	return it->second;
}

void setLast(char c, int l){
/*	if ('0' <= c && c <= '9'){
		last[c - '0'] = l;
	}
	last[c - 'a' + 10] = l;*/
	mapa[c] = l;
}

int main(){

	int n;
	string palavra;

	cin >> n;

	cin >> palavra;
/*
	for (int i = 0; i < 1000000; i++){
		last[i] = -1;
	}*/

	int maior = 0;
	int atual = 0;
	int inicio = 0;
	for (int i = 0; i < n; i++){
		if (getLast(palavra[i]) < inicio){
			atual++;
			setLast(palavra[i], i);
			maior = max(maior, atual);
		}
		else{
			inicio = getLast(palavra[i]) + 1;
			atual = i - getLast(palavra[i]);
			setLast(palavra[i], i);
		}
	}

	printf("%d\n", maior);

	return 0;
}