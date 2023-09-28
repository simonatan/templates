int n;
int t[2 * MX];

void op(int c1, int c2) {
	// some operation
}

void build() {
	for(int i = n - 1; i > 0; i--) {
		t[i] = op(t[i << 1], t[i << 1 | 1]); 
	}
}

void upd(int p, int val) {
	for(t[p += n] = val; p > 1; p >>= 1) {
		t[p >> 1] = op(t[p], t[p ^ 1]);
	}
}

int calc(int l, int r) {
	int res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = op(res, t[l++]);
		if (r & 1) res = op(res, t[--r]);
	}
	return res;
}
