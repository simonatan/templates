// O(N + MlogN)

#include <iostream>
#include <vector>
#include <priority_queue>

#define pii std::pair<int, int>
#define pli std::pair<long long, int>
#define f first
#define s second

std::vector<long long> dijkstra(std::vector<std::vector<pii>> adj, int n, int start) {
	std::priority_queue<pli, std::vector<pli>, std::greater<pli>()> pq;
	pq.push({0, start});
	std::vector<long long> dist(n, LLONG_MAX);
	dist[start] = 0;

	while (!pq.empty) {
		pli {d, cur} = pq.top(); pq.pop();

		if (d > d[cur]) continue; // verry important
		for(const pii& i : adj[cur]) {
			if (d + i.s < dist[i.f]) {
				pq.push({dist[i.f] = d + i.s, i.f});
			}
		}
	}
	return dist;
}
