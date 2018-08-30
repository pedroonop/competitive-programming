#include <bits/stdc++.h>
#define ii pair <int, int>
#define in pair <int, Node>
#define iiv pair <ii, vector<int> >
#define iv pair <int, vector<int> >
#define ff first
#define ss second
#define iii pair <ii, int>
#define INF 0x3f3f3f3f
#define MAXN 1000010
#define go(i,n) for (int i = 0; i < (int) n; i++)
#define goK(i,n,k) for (int i = 1; i <= (int) n-k; i++)
#define lld long long int
using namespace std;

lld bit [MAXN];
lld n;
	

void update (int i, int val){
	if (i <= 0) return;
	//printf ("###UPDATE###\n");
	for (; i <= MAXN; i += (i&-i)){
		bit[i] += val;
		//printf ("i = %d\n", i);
	}
}

lld busca (int i){
	if (i <= 0) return 0;
	//printf ("###busca###\n");
	lld ans = 0;
	for (; i; i -= (i&-i))
		ans += bit[i];
	return ans;
}

lld v[MAXN];

int main (){
	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	scanf ("%lld", &n);
	while (n != 0){
		memset (bit, 0, sizeof(bit));
		go(i,n){
			scanf ("%lld", &v[i]);
		}
		printf ("MENSAGEM: [");
		go(i,n){
			if (v[i] == 18){
				update(v[i+1], v[i+3]);
				update(v[i+2]+1, -v[i+3]);
				i += 3;
			}
			else if (v[i] == 42){
				lld ans = busca(v[i+1])-busca(v[i+1]-1);
				if (ans < 0) printf (" ");
				else printf ("%c", s[ans%26]);
				i++;
			}
			else if (v[i] == 0){
				break;
			}
		}
		printf ("]\n");
		scanf ("%lld", &n);
	}
	return 0;
}
