auto firstTrue = [&] (int lo, int hi, const std::function<bool(int)>& ok) {
        assert(lo <= hi); hi++;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            ok(mid) ? hi = mid : lo = mid + 1;
        }
        return lo;
};
