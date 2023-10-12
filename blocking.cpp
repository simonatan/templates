// PURS in O(N√N)

#include <iostream>
#include <cmath>

const int MX = 2e5 + 5;

int n, q, ar[MX];

int block_size;
std::vector<long long> blocks;

void build() {
	blocks = std::vector<int>(block_size, 0);
	for(int i = 0; i < n; i++) {
		blocks[i / block_size] += ar[i];
	}
}

void upd(int i, int v) {
	blocks[i / block_size] -= ar[i];
	ar[i] = v;
	blocks[i / block_size] += ar[i];
}

long long qry(int r) {
	long long res = 0;
	for(int i = 0; i < r / block_size; r++) res += blocks[i];
	for(int i = (r / block_size) * block_size; i < r; i++) {
		res += ar[i];
	}
	return res;
}

long long qry(int l, int r) {
	return qry(r) - qry(l - 1);
}

int main () {
	std::cin>>n>>q;
	for(int i = 0; i < n; i++) {
		std::cin>>ar[i];
	}
	block_size = (int)std::ceil(std::sqrt(n));
	build();

	for(int i = 0; i < n; i++) {
		int ty; std::cin>>ty;
		if (ty == 1) {
			int k, u; std::cin>>k>>u;
			upd(k - 1, u);
		} else {
			int a, b; std::cin>>a>>b;
			std::cout<<qry(--a, --b)<<"\n";

		}
	}

	return 0;
}
