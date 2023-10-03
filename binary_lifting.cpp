// O(NlogN) build
// O(logN) per query
// 0 - indexed

#include <iostream>
#include <vector>

const int MX = 1e5 + 5;
const int MXE = 20; // log2 MX

int n, q;
std::vector<int> adj[MX];
int up[MX][MXE], depth[MX];

void dfs(int cur, int prev) {
	for(int e = 1; e < MXE; e++) {
		up[cur][e] = up[up[cur][e - 1]][e - 1];
	}

	for(const int& i : adj[cur]) {
		if (i != prev) {
			depth[i] = depth[up[i][0] = cur] + 1;
			dfs(i, cur);
		}
	}
}

int lift(int node, int k) {
	for(int e = 0; e < MXE; e++) {
		if (k & (1 << e)) {
			node = up[node][e];
		}
	}
	return node; // -1 if such an ancestor doesn't exist
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) std::swap(a, b);
	b = lift(b, depth[b] - depth[a]);
	if (a == b) return a;
	for(int e = mxe - 1; e >= 0; e--) {
		if (up[a][l] != up[b][l]) {
			a = up[a][l]; b = up[b][l];
		}
	}
	return up[a][0];
}

int dist(int a, int b) {
	return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main () {
	std::cin>>n>>q;
	for(int i = 0; i < n; i++) {
		int a, b; std::cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	up[0][0] = -1; depth[0] = 0;
	dfs(0, -1);

	return 0;
}
