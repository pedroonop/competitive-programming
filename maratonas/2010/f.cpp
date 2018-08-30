#include <bits/stdc++.h>

using namespace std;

#define llu long long unsigned
#define lld long long int
#define ii pair<int, int>
#define x first
#define y second
#define pb(x) push_back(x)
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define go1(i,n) for (int i = 1; i <= (int)n; i++)
#define vi vector <int>
#define vii vector <ii>
#define INF 0x3f3f3f3f
#define ff first
#define ss second

int pontos[105];
int pilotos[105];

int provas[105][105];
int pontuacao[105][105];

int main(){
	int g, p, a, k,s;
	while (scanf ("%d %d", &g, &p) == 2){
		if (g == 0 && p == 0) break;
		memset (provas, 0, sizeof(provas));
		memset (pontuacao, 0, sizeof(pontuacao));
		go1(i,g){
			go1(j,p){
				scanf ("%d", &provas[i][j]);
			}
		}
		scanf ("%d", &s);

		go (i,s){
			pontuacao[i][0] = 0;
			scanf ("%d", &k);
			go1(j,k){
				scanf ("%d", &pontuacao[i][j]);
			}
		}

		go(k,s){
			int maior = -1;
			int indice = -1;
			memset (pontos, 0, sizeof(pontos));
			go1(i,g){
				go1(j,p){
					pontos[j] += pontuacao[k][provas[i][j]];
					if (pontos[j] > maior){
						maior = pontos[j];
						indice = j;
					}
				}
			}
			bool flag = true;
			go1(i,p){
				if (pontos[i] == maior)
					if (flag){
						printf("%d", i);
						flag = false;
					}
					else{
						printf(" %d", i);
					}
			}
			printf("\n");
		}
	}
	return 0;
}