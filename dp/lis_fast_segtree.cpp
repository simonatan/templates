// O(NlogN)

int t[2 * MX], n;

void upd(int i, int v) {
	for(t[i += n] = v; i > 1; i >>= 1) {
		t[i >> 1] = std::max(t[i], t[i ^ 1]);
	}
}

int mx(int r, int l = 0) {
	int res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = std::max(res, t[l++]);
		if (r & 1) res = std::max(res, t[--r]);
	}
	return res;
}

int lis_fenwick(const std::vector<int>& a) {
	n = a.size();
	int dp[MX];
	std::fill(t, t + 2 * MX, 1);

	// ! compress original array, if needed
	int ans = 0;
	for(int i = 0; i < n; i++) {
		dp[i] = mx(a[i] - 1);
		upd(ar[i], dp[i]);
		ans = std::max(ans, dp[i]);
	}
	return ans;
}
