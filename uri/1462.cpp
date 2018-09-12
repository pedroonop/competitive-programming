#include <bits/stdc++.h>
#define N 100100
#define llu unsigned long long int
using namespace std;

int main() {
    llu n;
    llu graus[N];
    llu bin, H[N], T[N];
    short deu;
    while(scanf("%llu", &n) == 1) {
        deu = 1;
        for(llu i = 0; i < n; i++) {        
            scanf("%llu", &graus[i]);
        }

        sort(graus, graus+n);

        H[0] = graus[0];
        T[0] = graus[0];
        for(llu i = 1; i < n; i++) {
            H[i] = H[i - 1] + graus[i];
            T[i] = T[i - 1] + min(graus[i], i);
        }

        if(H[n - 1] % 2 != 0 || H[0] >= n)
            deu = 0;
        for(llu i = 0; i < n && deu; i++) {
            bin = (unsigned long long int) ((i + 1LL) * i);
            if(H[i] > bin + T[n - 1] - T[i])
                deu = 0;
        }
        if(deu)
            printf("possivel\n");
        else
            printf("impossivel\n");
    }
    return 0;
}
