/*
* @Author: Pedro Torres
* @Date:   2018-09-03 14:47:55
* @Last Modified by:   Pedro Torres
* @Last Modified time: 2018-09-04 09:43:04
*/

#include<bits/stdc++.h>

#define pb push_back
#define MAXN 101

using namespace std;

typedef struct{
	double m[MAXN][MAXN];
}M;

vector<int> g[MAXN];

M m_mul(M a, M b, int tam){
    M c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            for (int k = 0; k < tam; k++)
                c.m[i][j] += a.m[i][k] * b.m[k][j];
    return c;
}

M m_exp(M a, int n, int tam){
    M b;
    if (n == 1)
        return a;
    else if (n % 2 == 0){
        b = m_exp(a, n / 2, tam);
        b = m_mul(b, b, tam);
        return b;
    }
    else{
        b = m_exp(a, (n - 1) / 2, tam);
        b = m_mul(b, b, tam);
        return (m_mul(b, a, tam));
    }
}

int main(){
	int n, a, b, c;
	int u, v;
	M mt;

	while(scanf("%d %d %d %d" ,&n ,&a ,&b, &c) != EOF){
		memset(mt.m, 0, sizeof(mt.m));
		for (int i = 0; i < MAXN; i++){
			g[i].clear();
		}
		for (int i = 0; i < n - 1; i++){
			scanf("%d %d" ,&u ,&v);

			g[u].pb(v);
			g[v].pb(u);
		}

		g[b].clear();
		g[c].clear();

		for (int i = 1; i <= n; i++){
			if (i == b || i == c){
				mt.m[i][i] = 1.0;
			}
			else{
				for (int j = 0; j < (int) g[i].size(); j++){
					mt.m[i][g[i][j]] = 1.0 / ((int) g[i].size() * 1.0);
				}
			}
		}

		//2^13
		mt = m_exp(mt, 8192, MAXN);

		printf("%.6lf\n" ,mt.m[a][b]);
	}

	return 0;
}