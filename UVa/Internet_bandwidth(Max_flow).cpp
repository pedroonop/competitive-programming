#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
#define go(i,n) for (int i = 0; i < (int)n; i++)
#define MAX_V 100 // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
#define INF 0x3f3f3f3f

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
vi p;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
  if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
  else if (p[v] != -1) {
	  augment(p[v], min(minEdge, res[p[v]][v])); // recursive
      res[p[v]][v] -= f; res[v][p[v]] += f;
  }       // update
}

int main() {
  
  int n, w, m;
  int a,b;
  int cont = 0;
  while (scanf ("%d", &n) == 1){
	  cont++;
	  if (n == 0) break;
	  scanf ("%d %d %d", &s, &t, &m);
	  go(i,m){
		  //printf ("a\n");y
		  //scanf (" %c %c %d", &a, &b, &w);
		  cin >> a >> b >> w;
		  res[a][b] = max(w, res[a][b]);
		  res[b][a] = max(w,res[b][a]);
	  }
	 
	  mf = 0;
	  while (1) {
		f = 0;
		vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
		p.assign(MAX_V, -1);           
		while (!q.empty()) {
		  int u = q.front(); q.pop();
		  if (u == t) break;  
		  for (int v = 0; v < MAX_V; v++)
			if (res[u][v] > 0 && dist[v] == INF)
			  dist[v] = dist[u] + 1, q.push(v), p[v] = u;
		}
		augment(t, INF);
		if (f == 0) break;
		mf += f;                
	  }
	  printf ("Network %d\n", cont);
	  printf("The bandwidth is %d.\n\n", mf);
	  
  }
  return 0;
}
