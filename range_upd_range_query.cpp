// https://cses.fi/problemset/task/1735

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <map>
#include <stack>
#include <algorithm>

#define dbg(v) std::cerr<<#v<<" = "<<v<<"\n";
#define show(x) std::cerr<<#x<<": "; for(auto i : x) std::cerr<<i<<" "; std::cerr<<"\n";
#define fast_io std::cin.tie(0)->sync_with_stdio(0);
#define all(x) x.begin(), x.end()
//#define uniq(x) x.erase(std::unique(all(x)), x.end())
#define pii std::pair<int, int>
#define f first
#define s second

using ll = long long;
const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
const int MAX_VAL = 1e9;
const double MAX_ERROR = 1e-7;
const ll INF = 1e10 - 1;

template <class T> bool min(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T> bool max(T& a, const T& b) {
    return b > a ? a = b, 1 : 0;
}

int n, q;
int ar[MX];

struct node {
    ll val, add, set;
    node() : val(0), add(0), set(0) {};
} t[4 * MX];

void pull(int x) {
    t[x].val = t[x << 1].val + t[x << 1 | 1].val;
}

void push(int x, int lx, int rx) {
    int mid = (lx + rx) >> 1;
    if (t[x].set != 0) {
        t[x << 1].set = t[x << 1 | 1].set = t[x].set;
        t[x << 1].val = (mid - lx + 1) * t[x << 1].set;
        t[x << 1 | 1].val = (rx - mid + 1) * t[x << 1 | 1].set;
        t[x << 1].add = t[x << 1 | 1].add = 0;
        t[x].set = 0;
    } else if (t[x].add != 0) {
        if (t[x << 1].set == 0) t[x << 1].add += t[x].add;
        else {
            t[x << 1].set += t[x].add;
            t[x << 1].add = 0;
        }

        if (t[x << 1 | 1].set == 0) t[x << 1 | 1].add += t[x].add;
        else {
            t[x << 1 | 1].set += t[x].add;
            t[x << 1 | 1].add = 0;
        }

        t[x << 1].val += (mid - lx + 1) * t[x].add;
        t[x << 1 | 1].val += (rx - mid + 1) * t[x].add;
        t[x].add = 0;
    }
}

void build(int x = 0, int lx = 0, int rx = n - 1) {
    t[x] = node();
    if (lx == rx) {
        t[x].val = ar[x];
        return;
    }
    int mid = (lx + rx) >> 1;
    build(x << 1, lx, mid);
    build(x << 1 | 1, mid + 1, rx);
    pull(x);
}

void add(ll v, int l, int r, int x = 0, int lx = 0, int rx = n - 1) {
    if (l > rx || r < lx) return;
    if (l <= lx && rx <= r) {
        t[x].val += (rx - lx + 1) * v;
        if (t[x].set == 0) t[x].add += v;
        else t[x].set += v;
        return;
    }
    push(x, lx, rx);
    int mid = (lx + rx) >> 1;
    add(v, l, r, x << 1, lx, mid);
    add(v, l, r, x << 1 | 1, mid + 1, rx);
    pull(x);
}

void set(ll v, int l, int r, int x = 0, int lx = 0, int rx = n - 1) {
    if (l > rx || r < lx) return;
    if (l <= lx && rx <= r) {
        t[x].val = (rx - lx + 1) * v;
        t[x].add = 0;
        t[x].set = v;
        return;
    }
    push(x, lx, rx);
    int mid = (lx + rx) >> 1;
    set(v, l, r, x << 1, lx, mid);
    set(v, l, r, x << 1 | 1, mid + 1, rx);
    pull(x);
}

ll query(int l, int r, int x = 0, int lx = 0, int rx = n - 1) {
    if (l > rx || r < lx) return 0;
    if (l <= lx && rx <= r) {
        return t[x].val;
    }
    push(x, lx, rx);
    int mid = (lx + rx) >> 1;
    return query(l, r, x << 1, lx, mid) + query(l, r, x << 1 | 1, mid + 1, rx);
}

int main () {
    fast_io;
    std::cin>>n>>q;
    for(int i = 0; i < n; i++) {
        std::cin>>ar[i];
    }

    for( ; q; q--) {
        int ty; std::cin>>ty;
        int a, b; std::cin>>a>>b; --a; --b;
        if (ty == 1) {
            int x; std::cin>>x;
            add(x, a, b);
        } else if (ty == 2) {
            int x; std::cin>>x;
            set(x, a, b);
        } else {
            std::cout<<query(a, b)<<"\n";
        }
    }
    
    return 0;
}
