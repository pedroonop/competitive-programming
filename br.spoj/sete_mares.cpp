#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define vi vector<int>
#define MAXN 9
#define ii pair <int, int>
#define vvc vector<vector<char> >
#define x first
#define y second
typedef struct {
	vvc matriz;
	ii posicao_atual;
	int mov;
}Jogo;

int movI[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int movJ[] = {-1,0,1, -1, 1, -1, 0, 1};


map <vvc, int> seen;
int dist (ii pos, ii pos2){
	int ans = fabs(pos.x-pos2.x) + fabs(pos.y - pos2.y);
	return ans;
}

bool valido (int i, int j){
	if (i < 0 || j < 0 || i >= 9 || j >= 8) return false;
	return true;
}

bool ganhou (vvc matriz){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 8; j++){
			if (matriz[i][j] == 'E') return false;
		}
	}
	return true;
}

vvc gera_matriz (vvc matriz, ii pos, bool *flag){
	vvc newMatriz;
	newMatriz.resize(9);
	for (int i = 0; i < 9; i++){
		newMatriz[i].resize(8);
		for (int j = 0; j < 8; j++){
			if (matriz[i][j] != 'E') newMatriz[i][j] = matriz[i][j];
			else newMatriz[i][j] = 'X';
		}
	}
	for (int i = 0; i < (int)matriz.size(); i++){
		for (int j = 0; j < (int)matriz[i].size(); j++){
			int mini = 1000;
			if (matriz[i][j] == 'E'){
				ii pos_fim;
				for (int x = 0; x < 8; x++){
					if (valido(i+movI[x],j+movJ[x])){
						ii pos2 = ii(i+movI[x],j+movJ[x]);
						if (mini > dist(pos, pos2)){
							mini = dist(pos,pos2);
							pos_fim = pos2;
						}
					}
				}
				if (newMatriz[pos_fim.x][pos_fim.y] == 'S') *flag = true;
				else if (newMatriz[pos_fim.x][pos_fim.y] == '#') {if (newMatriz[i][j] == 'X') newMatriz[i][j] = '.';}
				else {
					if (newMatriz[pos_fim.x][pos_fim.y] == 'E')
						newMatriz[pos_fim.x][pos_fim.y] = '#';
					else newMatriz[pos_fim.x][pos_fim.y] = 'E';
					if (newMatriz[i][j] == 'X') newMatriz[i][j] = '.';
				}
			}
		}
	}
	
	return newMatriz;
}

void mostra (vvc matriz){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 8; j++){
			printf ("%c", matriz[i][j]);
		}
		printf ("\n");
	}
}
queue <Jogo> q;
int main (){
	int n;
	scanf ("%d", &n);
	while (n--){
		q = queue<Jogo>();
		seen.clear();
		
		bool deuBom = false;
		Jogo x;
		x.matriz.resize(9);
		for (int i = 0; i < 9; i++){
			x.matriz[i].resize(8);
			for (int j = 0; j < 8; j++){
				scanf (" %c", &x.matriz[i][j]);
				if (x.matriz[i][j] == 'S') x.posicao_atual = ii(i,j);
			}
		}
		x.mov = 1;
		q.push(x);
		while (!q.empty()){
			Jogo topo = q.front();q.pop();
			if (seen[topo.matriz]) continue;
			seen[topo.matriz] = 1;
			if (topo.mov >= 10) continue;
			if (ganhou(topo.matriz)){
				printf ("I'm the king of the Seven Seas!\n");
				deuBom = true;
				break;
			}
			for (int i = 0; i < 8; i++){
				int newI = topo.posicao_atual.x+movI[i];
				int newJ = topo.posicao_atual.y+movJ[i];
				if (valido(newI, newJ) && topo.matriz[newI][newJ] != '#' && topo.matriz[newI][newJ] != 'E'){
					bool flag = false;
					Jogo newGame;
					newGame.matriz = topo.matriz;
					swap (newGame.matriz[topo.posicao_atual.x][topo.posicao_atual.y], newGame.matriz[newI][newJ]);
					newGame.matriz = gera_matriz(newGame.matriz, ii(newI, newJ), &flag);
					if (flag) continue;
					newGame.posicao_atual = ii(newI, newJ);
					newGame.mov = topo.mov + 1;
					q.push(newGame);
				}
			}
		}
		if (!deuBom) printf ("Oh no! I'm a dead man!\n");
		
	}
	
	
	return 0;
}
