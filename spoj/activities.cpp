#include <bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define x first
#define y second
#define ff first
#define ss second
#define vii vector<ii>
#define MAXN 100010
#define lld long long int
#define mod 100000000
int n;
vii v;
int memo[MAXN];
int memo2[MAXN];
int sumAcumulado[MAXN];
int add (int a, int b){
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int busca_b(int i){
    int incio = i+1, fim = v.size()-1;
    int primeiroV = v.size();
    while (incio <= fim){
        int meio = (incio+fim) >> 1;
        if (v[meio].ff >= v[i].ss){
            primeiroV = meio;
            fim = meio-1;
        }
        else {
            //primeiroV = meio;
            incio = meio+1;
        }
    }
    return primeiroV;
}

int dp (int i){
    if (i == v.size()-1) return 1;
    if (memo[i] != -1 ) return memo[i];
    int ans = 1;
    
    for (int j = busca_b(i); j < (int)v.size(); j++){
        ans = add(ans,dp(j));
    }
    return memo[i] = ans;
}

int dp_iterativo (){
    for (int i = 0; i < n; i++){
        memo2[i] = 1;
        sumAcumulado[i] = 1;
    }
    sumAcumulado[n] = 0;
    //sumAcumulado[n-1] = 1;
    int ans = 0;
    for (int i = n-2; i >= 0; i--){
        //for (int j = busca_b(i); j < n; j++){
          //  memo2[i] = add(memo2[i], memo2[j]);
        //}
        memo2[i] = add(sumAcumulado[i],sumAcumulado[busca_b(i)]);
        ans = add(ans, memo2[i]);
        sumAcumulado[i] = add(sumAcumulado[i+1],memo2[i]);
    }
    return ans;
}

int main(){
    while(scanf("%d", &n) == 1){
        if (n == -1) break;
        v.clear();
        //memset (memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++){
            ii aux;
            scanf ("%d %d", &aux.x, &aux.y);
            v.push_back(aux);        
        }
        sort (v.begin(), v.end());
        int ans = 0;
        //for (int i = 0; i < n; i++)
            //ans = add(ans,dp(i));
        printf ("%.8d\n", dp_iterativo()+1);
    }
    return 0;
}