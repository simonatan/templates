/* init - O(N)
union, find, find size, if connected - a(N)
*/

#include <iostream>
#include <vector>

struct DSU {
	// if x is the parent of the component e[x] = -(size of the comp); otherwise e[x] = parent
	std::vector<int> e;
	void init(int n) { e = std::vector<int>(n, -1); }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	int size(int x) { return -e[find(x)]; }
	bool connected(int x, int y) { return find(x) == find(y); }
	bool unify(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (e[x] > e[y]) std::swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};
