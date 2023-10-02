const int MX = 2e5 + 5;

int n;
int t[2 * MX], ar[MX];

// lsb = i & -i

void build() {
	for(int i = 0; i < n; i++) t[i] = ar[i];
	for(int i = 1; i < n; i++) {
		j = i + i & -i;
		if (j < n) t[j] += t[i];
	}
}

void add(int p, int v) {
	for( ; p < n; p += p & -p) t[p] += v;
}

long long sum(int r) {
	long long res = 0;
	for(; r; r -= r & -r) res += t[r];
	return res;
}

long long sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

void set(int p, int v) {
	int s = sum(p, p);
	add(p, v - s);
}
