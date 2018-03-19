#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct Edge {
	int from,to,dist;
	Edge (int u,int v,int d) : from(u),to(v),dist(d) {}
};
struct HeapNode {
	int d,u;
	bool operator < (const HeapNode & rhs) const {
		return d>rhs.d;
	}
};
const int maxn=1000,inf=99999999;
int d[maxn],p[maxn],n,m,i;
vector<Edge> edges;
vector<int> G[maxn];

void init(int s) {
	for (i = 0; i <=s; i++) G[i].clear();
	edges.clear();
}

void AddEdge (int from, int to, int dist) {
	edges.push_back(Edge(from, to, dist) );
	int L = edges.size();
	G[from].push_back(L-1);
}
void dijkstra(int s) {
	priority_queue<HeapNode> Q;
	for (i=1; i<=n; i++) d[i]=inf;
	d[s]=0;
	Q.push( (HeapNode) {0,s} );
	while(!Q.empty()) {
		HeapNode x = Q.top();	Q.pop();
		int  u=x.u;
		if (x.d!=d[u]) continue;
		int L=G[u].size();
		for (int i=0; i < L; i++) {
			Edge& e = edges[G[u][i]];
			if (d[e.to] > d[u] + e.dist ) {
				d[e.to] = d[u] + e.dist;
				p[e.to] = G[u][i];
				Q.push( (HeapNode) {d[e.to] , e.to} ) ;
			}
		}
	}
}

int main() {
	int from,to,dist,x;
	freopen("data.txt","r",stdin);
	while(cin>>n>>m>>x && n && m && x) {
		init(n);
		for (i=0; i<m; i++) {
			cin>>from>>to>>dist;
			AddEdge(from,to,dist);
		}
		dijkstra(x);
		for (i=1; i<=n; i++) cout<<d[i]<<" ";
	}
	return 0;
}
