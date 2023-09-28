const int MX = 2e5 + 5;

int n;
int t[MX], ar[MX];

// lsb = i & -i

void build() {
	for(int i = 0; i < n; i++) t[i] = ar[i];
	for(int i = 1; i < n; i++) {
		j = i & -i;
		if (j < n) t[j] += t[i];
	}
}

void add(int p, int v) {
	while (p < n) {
		t[p] += v;
		p += p & -p;
	}
}

long long sum(int r) {
	long long res = 0;
	while (r) {
		res += t[r];
		r -= r & -r;
	}
	return res;
}

long long sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

void set(int p, int v) {
	int s = sum(p, p);
	add(p, k - s);
}
