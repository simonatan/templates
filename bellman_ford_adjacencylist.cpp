// O(VE)

#include <iostream>
#include <vector>

#define pii std::pair<int, int> 
#define f first
#define s second

const int MX = 1e5 + 5;
const int INF = INT_MAX;

int n, m;
std::vector<pii> adj[MX]; // 0 - to, 1 - weight
int dist[MX];
bool vis[MX];

void dfs(int node) {
	vis[node] = true;

	for(const pii& i : adj[node]) {
		if (!vis[i.f]) {
			dist[i.f] = std::min(dist[i.f], dist[node] + i.s);
		}
	}
}

int main () {
	std::fill(dist, dist + MX, INF);
	dist[0] = 0;

	for(int i = 0; i < n; i++) {
		std::fill(vis, vis + MX, false);
		dfs(i);
	}

	return 0;
}
