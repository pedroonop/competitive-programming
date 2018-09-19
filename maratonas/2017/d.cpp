#include <bits/stdc++.h>
#define lld long long int
using namespace std;

const long long MN = 1001 * 100;
bool sieve[MN];
long long primes[MN];

void fillp() {
  memset(sieve, 0, sizeof sieve);
  sieve[1] = sieve[0] = 1;
  int p = 0;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      primes[p++] = i;
      for (long long j = i + i; j < MN; j += i)
        sieve[j] = true;
    }
  }
}

int main (){
  lld n;
  scanf ("%lld", &n);

  fillp();
  lld ans = 0;
  int raiz = sqrt(n)+5;
  lld n_ = n;
  
  vector<int> div;

  for (int i = 2; i <= raiz; i++){
      if (n%i == 0){
        div.push_back(i);
        if (i != n/i) div.push_back(n/i);
      }
  }
    printf("a\n");

  for (int x : div){
     if (!sieve[x]) continue;
     bool flag = true;
     int cont = 0, z = 0;
     while (x > 1){
        if(!flag) break;
        cont = 0;
        while (x%primes[z] == 0){
          printf("%d  %d\n", x, primes[z]);
          if (cont){
            flag = false;
            break;
          }
          x = x/primes[z];
          cont++;
        }
        z++;
     }
     printf("%d\n", x);
     if (x <= 1) ans++;
  }


  printf("%lld\n", ans);
  return 0;
}