#include <bits/stdc++.h>
#define go(i,n) for (int i = 0; i < (int)n; i++)

#define mid(l, r) 	       ((l + r) >> 1)

using namespace std;


typedef struct{
	int v[3];
}Node;


const int maxn  = 100000;
Node tree[4*maxn];
int lazy[4*maxn];
Node vazio;


void build(int node, int left ,int right){
	if(left == right){
		tree[node].v[0]++;
		//lazy[node] = 0;
		return;
	}
	
	int mid = mid(left,right);
	int esq = 2*node+1;
	int dir = 2*node+2;
	build(esq,left,mid);
	build(dir,mid+1,right);
	tree[node].v[0] = tree[esq].v[0] + tree[dir].v[0];
	//lazy[node] = 0;

}



void update_range( int node, int left, int right, int lq, int rq, int k){
  
  if( lazy[node] ){
  		int v[3];
  		memset (v,0,sizeof(v));
  		go(i,3){
  			v[i] = tree[node].v[(i+lazy[node])%3];
  		}
  		go(i,3){
  			tree[node].v[i] = v[i];
  		}
		//tree[node] = (right-left+1)*lazy[node];
		
		if( left != right ){ // tem filhos
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		
		lazy[node] = 0;
	}
  
  if( right < lq || left > rq )  // se o intervalo [lq,rq] está fora [left, right]
		return ;
  
  if(left >= lq && right <= rq){ // se o intervalo [lq,rq] cobre totalmente [left, right]
		
		//tree[node] = (right-left+1)*k;
  		int v[3];
  		memset (v,0,sizeof(v));
  		go(i,3){
  			v[i] = tree[node].v[(i+k)%3];
  		}
  		go(i,3){
  			tree[node].v[i] = v[i];
  		}
		//printf("[%d - %d] = %d\n", left+1, right+1, tree[node]);
		if( left != right ){ // tem filhos
			lazy[2*node+1] += k;
			lazy[2*node+2] += k;
		}
		
	}else{
		
		int mid = mid(left,right);
		int esq = 2*node+1;
		int dir = 2*node+2;
		update_range(esq,left,mid,lq,rq, k); 
		update_range(dir,mid+1,right,lq,rq, k);
		go(i,3){
			tree[node].v[i] = tree[esq].v[i] + tree[dir].v[i];
		}
    	//tree[node] = tree[2*node+1] + tree[2*node+2];
		//printf("[%d - %d] = %d\n", left+1, right+1, tree[node]);
		
  }
  
}


Node query(int node,int left ,int right ,int lq , int rq){
	
	if( lazy[node] ){
		//tree[node] = (right-left+1)*lazy[node];
		int v[3];
		memset (v,0,sizeof(v));
  		go(i,3){
  			v[i] = tree[node].v[(i+lazy[node])%3];
  		}
  		go(i,3){
  			tree[node].v[i] = v[i];
  		}
		if( left != right ){ // tem filhos
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		
		lazy[node] = 0;
	}
  
	if(right < lq || left > rq)
		return vazio;
		
	if(left >= lq && right <= rq)
		return tree[node];
	
	int mid = mid(left,right);
	Node p1 = query(2*node+1,left,mid,lq,rq); 
	Node p2 = query(2*node+2,mid+1,right,lq,rq);
	Node p3;

	go(i,3){
		p3.v[i] = p1.v[i] + p2.v[i];
	}

	return p3;
}



int main(){
	memset (vazio.v, 0, sizeof(vazio.v));
	int n, q;
	char op;
	int a, b, k;
	
	//cin >> n >> q;
	while (scanf ("%d %d", &n, &q) == 2){
		memset (tree, 0, sizeof(tree));
		memset (lazy, 0, sizeof(lazy));
		build(0, 0, n-1);
			
		for(int i = 1; i <= q; i++){
			
			scanf(" %c %d %d", &op, &a, &b);
			a--;
			b--;	
			
			if( op == 'M'){
				Node aux = query(0,0,n-1, a, b);
				int maior = -1;
				int indice = -1;
				go(i,3){
					if (maior < aux.v[i]){
						maior = aux.v[i];
						indice = i;
					}
				}
				//printf("maior %d\n", maior);
				if (maior > (b-a)/2)
					update_range(0, 0, n-1, a, b, 1);
			}else{
				//scanf("%d %d", &a, &b);
				Node aux = query(0,0,n-1, a,b);
				printf("%d", aux.v[0]);
				printf(" %d", aux.v[2]);
				printf(" %d", aux.v[1]);
				printf("\n");
				//printf("%d\n", query(0, 0, n-1, a, b) );
			}		
		}
		printf("\n");
	}
	 	
}
 
