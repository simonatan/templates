// O(EV)

#include <iostream>
#include <vector>

const int MX = 1005;
const int INF = INT_MAX;

struct Edge {
	int from, to, wei;
};

int n, m;
std::vector<Edge> edges;
int dist[MX];

int main () {
	std::fill(dist, dist + MX, INF);
	dist[0] = 0;
	for(int i = 0; i < n; i++) {
		for(Edge e : edges) {
			dist[e.to] = std::min(dist[e.to], dist[e.from] + e.wei);
		}
	}

	bool cycle = false;
	for(int i = 0; i < n; i++) {
		for(Edge e : edges) {
			if (dist[e.to] > dist[e.from] + e.wei) {
				dist[e.to] = INF; cycle = true;
			}
		}
	}
	// if dist[node] = INF then the node is a part of or affected by a negative cycle

	return 0;
}
