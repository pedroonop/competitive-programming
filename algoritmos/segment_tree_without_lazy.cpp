#include <bits/stdc++.h>

#define mid(l, r) 	       ((l + r) >> 1)

using namespace std;


const int maxn  = 100000;
int tree[4*maxn];
int arr[maxn];



void build(int node, int left ,int right)
{
	if(left == right)
	{
		tree[node] = arr[left];
		return;
	}
	
	int mid = mid(left,right);
	build(2*node+1,left,mid);
	build(2*node+2,mid+1,right);
	tree[node] = tree[2*node+1]*tree[2*node+2];
}

int query(int node,int left ,int right ,int lq , int rq)
{
	if(right < lq || left > rq)
		return 1;
		
	if(left >= lq && right <= rq)
		return tree[node];
	
	int mid = mid(left,right);
	int p1 = query(2*node+1,left,mid,lq,rq); 
	int p2 = query(2*node+2,mid+1,right,lq,rq);
	
	return p1*p2;
}


void update( int node, int left, int right, int i)
{
  
  if( left == right ){ 
		tree[node] = sinal(arr[left]);;
		return ;
	}
  
  if( i >= left && i <= right)
  {
    int mid = mid(left,right);
		if( i <= mid ) update(2*node+1 , left, mid, i);
    else update(2*node+2, mid + 1, right, i);
    tree[node] = tree[2*node+1] * tree[2*node+2];
  }
  
}



int main(){
	x--;
	y--;
	update(0, 0, n-1, x);
	query(0, 0, n-1, x, y);
	
	
	return 0;
}
