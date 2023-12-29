// we build the convex at the start and then answer queries
// O(NlogN)

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <map>
#include <stack>
#include <unordered_set>
#include <algorithm>

#define dbg(v) std::cerr<<#v<<" = "<<v<<"\n";
#define show(x) std::cerr<<#x<<": "; for(auto i : x) std::cerr<<i<<" "; std::cerr<<"\n";
#define fast_io std::cin.tie(0)->sync_with_stdio(0);
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(std::unique(all(x)), x.end())
#define pii std::pair<int, int>
#define f first
#define s second

using ll = long long;
const int MX = 5e5 + 5;
const int MOD = 1e9 + 7;
const int MAX_VAL = 1e6;
const double MAX_ERROR = 1e-7;
const int INF = 1e9 + 5;

template <class T> bool min(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T> bool max(T& a, const T& b) {
    return b > a ? a = b, 1 : 0;
}

// statement: you're given n lines {m_i; c} sorted by their slope and q query points xj. for each query
// find the min/max value of y_i = m_i * x_j + c_i.
// in this case we'll be finding the min but both cases are analogous

struct line {
    int m, c;
    bool operator >= (const line &o) const { return m >= o.m; } // sort by slope
};
std::istream& operator >> (std::istream& is, line &a) { return is >> a.m >> a.c; }

int n, q;
std::vector<line> lines;

ll intersection(line a, line b) {
    return (b.c - a.c) / (a.m - b.m);
}

bool check(line l1, line l2, line l3) { // if true we good, otherwise we continue popping lines
    return intersection(l1, l2) < intersection(l2, l3);
}

void add(line a) {
    while (lines.size() > 2 && !check(lines[lines.size() - 2], lines.back(), a)) {
        lines.pop_back();
    }
    lines.push_back(a);
}

std::vector<int> ints;

int main () {
    fast_io;
    std::iota(all(ints), 0);
    std::cin>>n;
    for(int i = 0; i < n; i++) {
        line a; std::cin>>a; add(a);
    }

    std::cin>>q;
    for(int i = 0; i < q; i++) {
        int x; std::cin>>x;
        // find position of x through binary search
        int ind = *std::lower_bound(ints.begin(), ints.begin() + (int)lines.size() - 1, x, [&] (int i, int x) {
            return intersection(lines[i], lines[i + 1]) < x;
        });
        std::cout<<lines[ind].m * x + lines[ind].c<<"\n";
    }
    
    return 0;
}
