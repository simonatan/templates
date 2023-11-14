#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <iomanip>
#include <numeric>
#include <map>
#include <stack>

#define dbg(v) std::cerr<<#v<<" = "<<v<<"\n";
#define fastIO std::cin.tie(0)->std::sync_with_stdio(0);
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(std::unique(all(x)), x.end())
#define show(x) for(auto i : x) std::cout<<i<<" "; std::cout<<"\n";
#define pii std::pair<int, int>
#define f first
#define s second

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
const double MAX_ERROR = 1e-7;
using ll = long long;

template <class T> bool min(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T> bool max(T& a, const T& b) {
    return b > a ? a = b, 1 : 0;
}
