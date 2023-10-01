// O(ElogE)

#include <iostream>
#include <vector>
#include <algorithm>

#define pii std::pair<int, int>
#define ppii std::pair<int, pii>
#define f first
#define s second

struct DSU {
	std::vector<int> e;
	void init(int n) { e = std::vector<int>(n, -1); }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	int size(int x) { return -e[find(x)]; }
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (e[x] > e[y]) std::swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int n, m;
std::vector<ppii> edges; // f - weight, s - nodes

long long kruskal() {
	DSU d; d.init(n);
	std::sort(edges.begin(), edges.end());

	long long ans = 0;
	for(ppii& i : edges) {
		if (d.unite(i.s.f, i.s.s)) {
			ans += i.f;
		}
	}

	return d.size(1) == n ? ans : -1; // if some of the nodes aren't connected there's no MST
} 
