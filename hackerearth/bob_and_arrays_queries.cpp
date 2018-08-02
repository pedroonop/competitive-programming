#include <bits/stdc++.h>
#define MAXN 500005
#define lld unsigned long long int
#define MID(l,r)     ((l+r) >> 1)
#define MASK  (1LL << 63)
using namespace std;

lld tree[4*MAXN];
lld vetor[MAXN];



void build (int node, int left, int right){
    if (left == right){
        tree[node] = vetor[left];
        return;
    }
    int mid = MID(left, right);
    build (2*node+1, left, mid);
    build (2*node+2, mid+1, right);
    tree[node] = tree[2*node+1]+tree[2*node+2];
    
}

void update (int node, int left, int right, int i, bool flag){
    if (left == right){
        //tree[node] = vetor[left];
        //return;
        if (flag){
			if (!(vetor[left] & MASK)){
				tree[node] += 1;
			}
			//vetor[left] = (vetor[left] * 2)+1;
			vetor[left] = vetor[left] << 1;
			vetor[left] += 1;
		}
		else{
			if (vetor[left] & 1) tree[node] -= 1;
			vetor[left] = (vetor[left] >> 1);
		}
		return;
    }
    if (i >= left && i <= right){
        int mid = MID(left, right);
        if (i <= mid) update(2*node+1, left, mid, i, flag);
        else update (2*node+2, mid+1, right, i, flag);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}

int query(int node,int left ,int right ,int lq , int rq){ //O(logN) para buscar na segtree
	if(right < lq || left > rq)
		return 0;
		
	if(left >= lq && right <= rq)
		return tree[node];
	
	int mid = MID(left,right);
	int p1 = query(2*node+1,left,mid,lq,rq); 
	int p2 = query(2*node+2,mid+1,right,lq,rq);
	return p1+p2;
}

int main (){
	//printf ("%lld", (1LL << 63));
	int n,q, a, b, op;
	scanf ("%d %d", &n, &q);
	build (0, 0, n-1);
	while (q--){
		scanf ("%d %d", &op, &a);
		a--;
		if (op == 1){
			update (0, 0, n-1, a, true);
		}
		else if (op == 2){
			update (0, 0, n-1, a, false);
		}
		else{
			scanf ("%d", &b);
			b--;
			printf ("%d\n", query(0, 0, n-1, a, b));
		}
	}
	
	return 0;
}
