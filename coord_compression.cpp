void coord_compression(std::vector<int> a, int n) {
  std::vector<int> b = a;
  std::sort(b.begin(), b.end());
  b.resize(std::unique(b.begin(), b.end()) - b.begin());
  for(int i = 0; i < n; i++) {
    a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  }
}
