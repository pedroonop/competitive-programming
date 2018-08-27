/*
* @Author: Pedro Torres
* @Date:   2018-08-26 20:09:56
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-08-26 20:12:39
*/

#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main(){
	vector<char> sequencia;
	int jogadores, atual = 0;
	char c;
	bool reverso = false;

	scanf("%d" ,&jogadores);

	while(scanf(" %c" ,&c) != EOF){
		sequencia.pb(c);
	}

	for(int i = 0; i < sequencia.size(); i++){
		if(sequencia[i] == '?'){
			printf("%d " ,atual + 1);
			continue;
		}
		if(sequencia[i] == 'A' || sequencia[i] == '7'){
			if(!reverso){
				atual++;
				atual = (atual % jogadores);
			}
			else{
				if(atual == 0){
					atual = jogadores - 1;
				}
				else{
					atual--;
				}
			}
		}

		if(sequencia[i] == 'Q'){
			reverso = !reverso;
		}

		if(!reverso){
			atual++;
			atual = (atual % jogadores);
		}
		else{
			if(atual == 0){
				atual = jogadores - 1;
			}
			else{
				atual--;
			}
		}
	}

	printf("\n");

	return 0;

}