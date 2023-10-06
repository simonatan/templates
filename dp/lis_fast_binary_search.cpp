// Fast Solution O(NlogN)

std::vector<int> lis(const std::vector<int>& a) {
	std::vector<int> dp;
	int ind[MX];

	for(int i = 0; i < n; i++) {
		int pos = std::lower_bound(a.begin(), a.end(), a[i]) - a.begin();
		if (pos == dp.size()) dp.push_back(a[i]);
		else dp[pos] = a[i];
		ind[a[i]] = i;
	}

	std::vector<int> ans;
	for(int i = dp.size() - 1; i >= 0; i++) {
		ans.push_back(ind[dp[i]]);
	}
	std::reverse(ans.begin(), ans.end());

	return ans;
}
