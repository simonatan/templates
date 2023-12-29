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

// CHT
// + lines are inserted in arbitrary order
// + query positions are in arbitrary order

struct line {
    bool type; // 0 for slope sort, 1 for finding pos of x
    double x; // intersection with line on the left (previous line on convex hull)
    ll m, c;
    bool operator < (const line &o) const {
        if (type) return x < o.x;
        return m < o.m; 
    }
};

std::set<line> cht;
ll hei[MX], w[MX];
ll dp[MX];

bool has_prev(std::set<line>::iterator it) { return it != cht.begin(); }
bool has_next(std::set<line>::iterator it) { return it != cht.end() && next(it) != cht.end(); }

double intersect(std::set<line>::iterator l1, std::set<line>::iterator l2) {
    return (double)(l2->c - l1->c) / (double)(l1->m - l2->m);
}

bool bad(std::set<line>::iterator it) {
    if (has_next(it) && next(it)->c <= it->c) return true;
    return (has_prev(it) && has_next(it) && intersect(prev(it), next(it)) <= intersect(prev(it), it));
}

void add_new_x(std::set<line>::iterator it) {
    if (has_prev(it)) {
        line l = *it;
        l.x = intersect(prev(it), it);
        cht.insert(cht.erase(it), l);
    }
}

void add_line(ll m, ll c) {
    std::set<line>::iterator it;
    
    it = cht.lower_bound({0, 0, m, c}); // find pos in convex hull
    if (it != cht.end() && it->m == m) {
        if (it->c <= c) return; // line doesn't appear in convex
        cht.erase(it);
    }
    
    it = cht.insert({0, 0, m, c}).f;
    if (bad(it)) cht.erase(it);
    else {
        while (has_prev(it) && bad(prev(it))) cht.erase(prev(it));
        while (has_next(it) && bad(next(it))) cht.erase(next(it));
        if (has_next(it)) add_new_x(next(it));
        add_new_x(it);
    }
}

ll query(ll h) { 
    line l = *prev(cht.upper_bound({1, (double)h, 0, 0}));
    return l.m * h + l.c;
}

int main () {
    fast_io;
    int n; std::cin>>n;
    for(int i = 1; i <= n; i++) {
        std::cin>>hei[i];
    }
    ll tot = 0;
    for(int i = 1; i <= n; i++) {
        std::cin>>w[i];
        tot += w[i];
    }
    
    dp[1] = -w[1];
    for(int i = 2; i <= n; i++) {
        add_line(-2 * hei[i - 1], dp[i - 1] + hei[i - 1] * hei[i - 1]);
        dp[i] = query(hei[i]) - w[i] + hei[i] * hei[i]; 
    }
    
    std::cout<<tot + dp[n]<<"\n";

    return 0;
}
