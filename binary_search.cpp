
// lamdba
#include <functional>

auto firstTrue = [&] (int lo, int hi, const std::function<bool(int)>& ok) {
        assert(lo <= hi); hi++;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            ok(mid) ? hi = mid : lo = mid + 1;
        }
        return lo;
};

// ===========================================================================

// template (preferred)
template <class T, class U> T firstTrue(T lo, T hi, U ok) {
    assert(lo <= hi); hi++;
    while (lo < hi) {
        int m = lo + (hi - lo) / 2;
        ok(m) ? hi = m : lo = m + 1;
    }
    return lo;
}
