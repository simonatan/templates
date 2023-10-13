#include <iostream>
#include <vector>

const int MX = 2e5 + 5;

int n, q, v[MX];
std::vector<int> adj[MX];

int sz[MX], par[MX], dep[MX];
int t[2 * MX], id[MX], top[MX], heavy[MX];

void build() {
	for(int i = n - 1; i > 0; i--) {
		t[i] = std::max(t[i << 1], t[i << 1 | 1]);
	}
}

void upd(int i, int v) {
	for(t[i += n] = v; i; i >>= 1) {
		t[i >> 1] = std::max(t[i], t[i ^ 1]);
	}
}

int max(int l, int r) {
	int ra = 0, rb = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ra = std::max(ra, t[l++]);
		if (r & 1) rb = std::max(rb, t[--r]);
	} 
	return std::max(ra, rb);
}

int dfs(int cur = 0) {
	sz[cur] = 1; heavy[cur] = -1;
	int mxsub = 0;
	for(const int& i : adj[cur]) {
		if (i != par[cur]) {
			par[i] = cur;
			dep[i] = dep[cur] + 1;
			int sub = dfs(i);
			if (sub > mxsub) {
				mxsub = sub;
				heavy[cur] = i;
			}
			sz[cur] += sub;
		}
	}
	return sz[cur];
}

int cnt = 0;
void decomp(int cur = 0) {
	id[cur] = cnt++;
	if (heavy[cur] != -1) {
		top[heavy[cur]] = top[cur];
		decomp(heavy[cur]);
	}
	for(const int& i : adj[cur]) {
		if (i != par[cur] && heavy[cur] != i) {
			top[i] = i; decomp(i);
		}
	}
}

int path(int x, int y) {
	int res = 0;
	for( ; top[x] != top[y]; x = par[top[x]]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		res = std::max(res, qry(id[top[x]], id[x]));
	}
	if (dep[x] < dep[y]) swap(x, y);
	res = std::max(res, qry(id[x], id[y]));
	return res;
}

int main () {
	std::cin>>n>>q;
	for(int i = 0; i < n; i++) {
		std::cin>>v[i]; t[i + n] = v[i];
	}
	for(int i = 0; i < n - 1; i++) {
		int a, b; std::cin>>a>>b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	build(); 
	par[0] = -1; dep[0] = 0;
	dfs();
	top[0] = 0;
	decomp();

	for(int i = 0; i < q; i++) {
		int ty; std::cin>>ty;
		if (ty == 2) {
			int a, b; std::cin>>a>>b;
			std::cout<<path(--a, --b)<<"\n";
		} else {
			int s, x; std::cin>>s>>x;
			v[--s] = x;
			upd(id[s], x);
		}
	}

	return 0;
}
