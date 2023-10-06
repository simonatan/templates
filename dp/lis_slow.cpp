// Slow solution O(N^2)

std::vector<int> lis(const std::vector<int>& a) {
	int n = a.size();
	int dp[MX], p[MX];

	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1; p[i] = j;
			}
		}
	}

	std::vector<int> ans;
	int mx = dp[0], mx_i = 0;
	for(int i = 1; i < n; i++) {
		if (mx < dp[i]) {
			mx = dp[i]; mx_i = i;
		}
	}

	int prev = mx_i; 
	while (mx) {
		ans.push_back(a[prev]);
		prev = p[prev]; mx--;
	}
	std::reverse(ans.begin(), ans.end());

	return ans; // num of elements - (int)ans.size();
}
