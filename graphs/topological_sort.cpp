// Topological sort using BFS 
// O(N + M)

#include <iostream>
#include <vector>
#include <queue>

const int MX = 1e5 + 5;

int n, m;
std::vector<int> adj[MX], order;

bool toposort() {
	int indeg[MX];
	std::queue<int> q; // priority_queue for lexicographical order
	for(int i = 0; i < n; i++) {
		if (indeg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.top(); q.pop();

		order.push_back(cur);
		for(const int& i : adj[cur]) {
			if (--indeg[i] == 0) q.push(i);
		}
	}

	if (order.size() < n) return false; // the graph contains a cycle
	else return true;
}
