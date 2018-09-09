#include <bits/stdc++.h>
#define vi vector <int>
#define MAXN 1004
#define ii pair <int, int>
using namespace std;


int seen[MAXN];
int d[MAXN];
int low[MAXN];
int corte[MAXN];
vector <ii> ponte;
vector <vi> g;
int tempo = 1;
int raiz;

void dfs (int v, int p){
    if (seen[v]){
        return;
    }
    int filhos = 0;
    d[v] = low[v] = tempo++;
    seen[v] = 1;
    int any = 0;
    for (int i = 0; i < (int)g[v].size(); i++){
        int u = g[v][i];
        if (!seen[u]){
            dfs (u, v);
            filhos++;
            if (low[u] >= d[v]){
                any = 1;
            }
            low[v] = min (low[v], low[u]);
            if (low[u] > d[v]) ponte.push_back(ii(v,u));
        }
        else if (u != p){
            low [v] = min (low[v], d[u]);
        }
    }
    if (v == raiz && filhos > 1){
        corte[v] = 1;
    }
    if (v != raiz && any){
        corte[v] = 1;
    }
}


int main (){
    int n,m,a,b;
    int t = 0;
     g.resize(MAXN);
    while (scanf ("%d %d", &n, &m) == 2 && ++t){
        if (n == 0) break;
        for (int i = 0; i < MAXN; i++){
            g[i].clear();
        }
        memset(seen, 0, sizeof(seen));
        memset(corte, 0, sizeof(corte));
        memset(d, 0, sizeof(d));
        memset(low, 0, sizeof(low));
        ponte.clear();
        for (int i = 0; i < m; i++){
            scanf ("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        raiz = 1;
        dfs (1,1);
        //printf ("Teste %d\n", t);
        //printf ("Pontes = %lu\n", ponte.size());
        if (ponte.size()){
            printf ("S\n");
        }
        else{
            printf ("N\n");
        }
        //bool flag = true;
        /*for (int i = 1; i <= n; i++){
            if (corte[i]){flag = false; printf ("%d ", i);}
        }*/
        //if (flag) printf ("nenhum");
        //printf("\n\n");
    }
    return 0;
}
