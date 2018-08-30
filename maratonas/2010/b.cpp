#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)

int main(){

	int n, m, s;

	scanf("%d %d %d", &n, &m, &s);

	char matr[101][101];

	int x, y;
	int o;

	while (n != 0){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf(" %c", &matr[i][j]);
				if (matr[i][j] != '.' && matr[i][j] != '*' && matr[i][j] != '#'){
					x = i;
					y = j;
					if (matr[i][j] == 'N') o = 0;
					if (matr[i][j] == 'L') o = 1;
					if (matr[i][j] == 'S') o = 2;
					if (matr[i][j] == 'O') o = 3;				
				}
			}
		}

		int cont = 0;

		char move;
		for (int i = 0; i < s; i++){
			scanf(" %c", &move);
			if (move == 'D') o = (o + 1) % 4;
			if (move == 'E'){
				o--;
				if (o < 0) o = 3;
			}
			if (move == 'F'){
				if (o == 0){
					if (x == 0 || matr[x - 1][y] == '#') continue;
					x--;
				}
				else if (o == 1){
					if (y == m - 1 || matr[x][y + 1] == '#') continue;
					y++;
				}
				else if (o == 2){
					if (x == n - 1 || matr[x + 1][y] == '#') continue;
					x++;
				}
				else{
					if (y == 0 || matr[x][y - 1] == '#') continue;
					y--;
				}
				if (matr[x][y] == '*'){
					cont++;
					matr[x][y] = '.';
				}
			}
		}

		printf("%d\n", cont);
		
		scanf("%d %d %d", &n, &m, &s);
	}


	return 0;
}