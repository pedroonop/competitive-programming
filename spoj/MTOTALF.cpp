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

map <char, int> m;
int indice_valido = 0;



int main() {
  int n, w;
  char a,b;
  scanf ("%d", &n);
  go(i,n){
	  //scanf (" %c %c %d", &a, &b, &w);
	  cin >> a >> b >> w;
	  if (m.find(a) == m.end()) m[a] = indice_valido++;
	  if (m.find(b) == m.end()) m[b] = indice_valido++;
	  res[m[a]][m[b]] += w;
	  res[m[b]][m[a]] += w;
  }
  s = m['A'];
  t = m['Z'];
  //printf ("%d %d\n", s, t);

  mf = 0;
  while (1) {
	//printf ("a\n");
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

  printf("%d\n", mf);
  return 0;
}
