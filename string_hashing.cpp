const long long M = 1e9 + 9; 
const long long B = 9973;

std::vector<long long> hash, p;
void gen(std::string& s) {
	hash.push_back(0);
	p.push_back(1);
	for(int i = 0; i < s.size(); i++) {
		long long cur = ((hash.back() * B) % M + s[i]) % M;
		hash.push_back(cur);
		p.push_back(p.back() * B % M);
	}
}

long long get_hash(int st, int en) {
	long long prev = hash[st] * p[en - st + 1] % M;
	return ((M + hash[en + 1]) - prev) % M;
}
