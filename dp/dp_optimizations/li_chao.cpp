// dynamic CHT 
// works in O(logC) where C is the max value of x; typically this number is not big enough to cause problems but if necessary you can always coordinate compress and then C = N
// better constant factor than CHT and easier to implement cuz she slays <3 (ref. lineContainer)

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

struct line {
    ll m, c;
    ll intersect(ll x) const { return m * x + c; }
} t[4 * MX];

void insert(line add, int x = 0, int lx = 0, int rx = MAX_VAL) {
    if (lx + 1 == rx) {
        if (add.intersect(lx) > t[x].intersect(lx)) t[x] = add;
        return;
    }
    int mid = (lx + rx) >> 1;
    if (t[x].m > add.m) std::swap(t[x], add);
    if (t[x].intersect(mid) < add.intersect(mid)) {
        std::swap(t[x], add);
        insert(add, x * 2 + 1, lx, mid);
    } else insert(add, x * 2 + 2, mid + 1, rx);
}

ll query(int v, int x = 0, int lx = 0, int rx = MAX_VAL) {
    if (lx + 1 == rx) { return t[x].intersect(v); }
    int mid = (lx + rx) >> 1;
    if (x < mid) return std::max(query(v, x * 2 + 1, lx, mid), t[x].intersect(v));
    else return std::max(t[x].intersect(v), query(v, x * 2 + 2, mid + 1, rx));
}

int main () {
    fast_io;
    int q; std::cin>>q;
    while (q--) {
        std::string A; std::cin>>A;
        if (A[0] == 'P') {
            ll a, b; std::cin>>a>>b;
            insert({b, a - b});
        } else {
            ll x; std::cin>>x;
            std::cout<<query(x)<<"\n";
        }
    }

    return 0;
}
