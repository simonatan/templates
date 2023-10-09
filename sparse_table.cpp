const int N = 2e5 + 5;
const int P = 20;

int st[P][N], lg2[P], ind[P][N];

void build(std::vector<int>& ar) { // O(NlogN)
	std::memset(lg2, lg2 + P, 0);
	for(int i = 2; i <= N; i++) {
		lg2[i] = lg2[i / 2] + 1;
	}
	for(int i = 0; i < N; i++) {
		st[0][i] = ar[i];
		ind[0][i] = i;
	}

	for(int p = 1; p <= P; p++) {
		for(int i = 0; i + (1 << p) <= N; i++) {
			int l = st[p - 1][i], r = st[p - 1][i + (1 << (p - 1))];
			st[p][i] = std::min(l, r); // or any other associative function
			if (l <= r) ind[p][i] = ind[p - 1][i];
			else ind[p][i] = ind[p - 1][i + (1 << (p - 1))];
		}
	}
}

int qry(int l, int r) { // O(1)
	int p = lg2[r - l + 1]; // or = 31 - std::__builtin_clz(r - l + 1);
	return std::min(st[p][l], st[p][r - (1 << p) + 1]);
}

int cascadingQry(int l, int r) { // O(logN), works on f(x) that aren't overlap friendly (+, *,...) 
	int ret = INT_MAX, len = r - l + 1;
	for(int p = P; p >= 0; p--) {
		if (len & (1 << p)) {
			ret = std::min(ret, st[p][l]);
			l += (1 << p);
		}
	}
	return ret;
}

int indexQry(int l, int r) {
	int p = lg2[r - l + 1]; // or = 31 - std::__builtin_clz(r - l + 1);
	if (st[p][l] <= st[p][r - (1 << p) + 1]) return ind[p][l];
	return ind[p][r - (1 << p) + 1];
}
