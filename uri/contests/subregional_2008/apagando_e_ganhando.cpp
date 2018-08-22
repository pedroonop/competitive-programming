#include <bits/stdc++.h>
using namespace std;

int main (){
    std::stack<char> pilha;
    std::vector<char> resposta ;
    int n, d;
    string palavra;
    while (scanf ("%d %d", &n, &d) == 2){
        if (n == 0 && d == 0) break;
        cin >> palavra;
        pilha.push(palavra[0]);
        for (int i = 1; i < palavra.size(); i++){
            while (!pilha.empty() && pilha.top() < palavra[i] && d != 0){
                pilha.pop();
                d--;
            }
            pilha.push(palavra[i]);
            
        }
        while (d != 0 && !pilha.empty()){
            pilha.pop();
            d--;
        }
        
        while (!pilha.empty()){
            resposta.push_back(pilha.top());
            pilha.pop();
        }
        for (int i = resposta.size()-1; i >= 0; i--){
            printf("%c", resposta[i]);
        }
        resposta.clear();
        printf("\n");
    }
	return 0;
}
