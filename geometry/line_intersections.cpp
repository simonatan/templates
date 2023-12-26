// could lead to overcounting, i might update it in the future
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
#include <algorithm>

#define dbg(v) std::cerr<<#v<<" = "<<v<<"\n";
#define show(x) std::cerr<<#x<<": "; for(auto i : x) std::cerr<<i<<" "; std::cerr<<"\n";
#define fast_io std::cin.tie(0)->sync_with_stdio(0);
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(std::unique(all(x)), x.end())
#define pii std::pair<int, int>
#define f first
//#define s second

using ll = long long;
const int MX = 2e5 + 2;
const int MOD = 1e9 + 7;
const int MAX_VAL = 1e6;
const double MAX_ERROR = 1e-7;
//const int INF = 1e9 + 5;

template <class T> bool min(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T> bool max(T& a, const T& b) {
    return b > a ? a = b, 1 : 0;
}

struct point {
    ll x, y;
    ll id;

    bool operator < (const point &o) const {
        return x == o.x ? y < o.y : x < o.x;
    }
};

point operator - (const point &a, const point &b) { return {a.x - b.x, a.y - b.y}; }
std::istream& operator >> (std::istream& is, point &a) { return is >> a.x >> a.y; }

ll sign(ll x) {
    if (x == 0) return 0;
    else x < 0 ? -1 : 1;
}

ll cross(point a, point b) { return sign(a.x * b.y - a.y * b.x); }

struct segment {
    point p1, p2;
    ll id;
};

ll sweep_line;

double intersection_with_sweepline(segment a) {
    if (a.p1.x == a.p2.x) return a.p1.y;
    return a.p1.y + (a.p2.y - a.p1.y) * (sweep_line - a.p1.x) / (a.p2.x - a.p1.x);
}

bool operator < (const segment &a, const segment &b) { // sorting by y intersection with the sweep-line
    return a.id != b.id && intersection_with_sweepline(a) <= intersection_with_sweepline(b);
}

bool intersect(segment x, segment y) {
    point a(x.p1.x, x.p1.y), b(x.p2.x, x.p2.y);
    point c(y.p1.x, y.p1.y), d(y.p2.x, y.p2.y);

    return cross(b - a, d - a) * cross(c - a, b - a) >= 0 &&
    cross(d - c, a - c) * cross(b - c, d - c) >= 0;
}

int main () {
    fast_io;
    int n; std::cin>>n;
    std::vector<segment> v;
    std::vector<point> events;
    for(int i = 0; i < n; i++) {
        point a, b; std::cin>>a>>b;
        v.push_back({a, b, i});
        events.push_back({a.x, a.y, i});
        events.push_back({b.x, b.y, i});
    }
    std::sort(all(events));

    std::set<segment> active;
    int first, cnt = 0; // segments we'll be checking for intersections
    for(int i = 0; i < 2 * n; i++) {
        first = events[i].id;
        sweep_line = events[i].x;

        auto it = active.find(v[first]);
        if (it == active.end()) {
            it = active.lower_bound(v[first]);
            if (it != active.end() && intersect(v[first], *it)) {
                cnt++;
            }
            if (it != active.begin()) {
                it--;
                if (intersect(v[first], *it)) {
                    cnt++;
                }
            }
            active.insert(v[first]);
        } else {
            auto after = next(it), before = it;
            if (after != active.end() && before != active.begin()) {
                before--;
                if (intersect(*after, *before)) {
                    cnt++;
                }
            }
            active.erase(it);
        }
    }
    
    std::cout<<cnt<<"\n";

    return 0;
}
