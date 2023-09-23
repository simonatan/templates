// https://www.youtube.com/watch?v=4NQ3HnhyNfQ&t=647s
// O(N^3) 
// usually on small graphs with N <= 500
// detects neg cycles; ASPS

#include <iostream>

const int MX = 1e5 + 5;
const int INF = 1e8;

int n, m;
int dp[MX][MX];

int main () {
	std::cin>>n>>m;
	std::fill(dp, dp[MX], INF);
	for(int i = 0; i < m; i++) {
		int a, b, c; std::cin>>a>>b>>c;
		--a; --b;
		if (c < dp[a][b]) dp[a][b] = dp[b][a] = c;
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
				dp[j][i] = dp[i][j];
			}
		}
	}

	bool cycle = false;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (dp[i][k] + dp[k][j] < dp[i][j]) {
					dp[i][j] = dp[j][i] = INF; cycle = true;
				}
			}
		}
	}

	return 0;
}
