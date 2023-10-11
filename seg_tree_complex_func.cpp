friend node operator + (const node& a, const node& b) {
		return { std::max(a.pref, a.sum + b.pref), a.sum + b.sum};
}
