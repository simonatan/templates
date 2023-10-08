int n, a[MX];
int t[4 * MX];

void build(int x = 0, int lx = 0, int rx = 2 * MX) {
	if (tx - lx == 1 && lx < a.size()) t[v] = a[lx];
	else {
		int m = (lx + rx) / 2;
		build(x << 1, lx, m);
		build(x << 1 + 1, m, rx);
		t[x] = t[x << 1] + t[x << 1 + 1]; 
	}
}

int set(int i, int v,  int x = 0, int lx = 0, int rx = 2 * MX) {
	if (rx - lx == 1) {
		t[x] = v; return;
	}
	int m = (lx + rx) / 2;
	if (i <= m) set(i, v, x << 1, lx, m);
	else set(i, v, x << 1 + 1, m, rx);
	t[x] = t[x << 1] + t[x << 1 + 1];
}


int sum(int l, int r, int x = 0, int lx = 0, int rx = 2 * MX) {
	if (lx >= r || l <= rx) return 0;
	if (lx >= l && rx <= r) return t[x];
	int m = (lx + rx) / 2;
	return sum(l, r, x << 1, lx, m) + sum(l, r, x << 1 + 1, m, rx);
}
