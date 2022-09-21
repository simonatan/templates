void compress(std::vector<int>& a) {
  int cnt = 0;
  std::map<int, int> m;
  for(auto x : a) m[x];
  for(auto& x : m) x.second = cnt++;
  for(auto& x : a) x = m[x];
}
