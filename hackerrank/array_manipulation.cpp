#include <bits/stdc++.h>
using namespace std;
#define llu long long unsigned
#define lld long long int
#define MAXN 10001000
int n;
lld bit[MAXN];

lld m = -1;

void update (int i, lld val){
    for (; i <= n+1; i += (i&-i)){
        bit[i] += val;
        m = max(m, bit[i]);
    }
    
}

lld query(int i){
    lld ans = 0;
    for (; i; i -= (i&-i)) ans += bit[i];
    return ans;
}

llu ans (){
    lld maior = -1;
    for (int i = 1; i <= n; i++) maior = max(maior, query(i));
    return maior;
}


int main (){
    //int m;
    //scanf ("%d %d", &n, &m);
    lld m;
    //scanf("%lld %lld", &n, &m);
    cin >> n >> m;
    while(m--){
        lld a,b,k;
        //scanf ("%lld %lld %lld", &a, &b, &k);
        cin >> a >> b >> k;
        update(a, k);
        update(b+1, -k);
        //bit[a] += k;
        //bit[b+1] += -k;
    }
    /*
    llu maior = 0;
    llu sum = 0;
    for (int i = 1; i <= n; i++){
        //bit[i] += bit[i-1];
        //if (bit[i] != bit[i-1]) bit[i]+= bit[i-1];
        sum += bit[i];
        maior = max(maior, sum);
    }*/
    
    //printf("%d\n", maior);
    cout << ans();
    return 0;
}
