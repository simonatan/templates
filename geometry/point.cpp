using t = double;
const t EPS = 1e-9;
using p = std::pair<t, t>;
using line = std::pair<p, p>;
#define f first
#define s second

t sq(t a) { return a * a; }
t norm(p a) { return sq(a.f) + sq(a.s); }
t abs(p a) { return sqrt(norm(a)); }
t arg(p a) { return std::atan2(a.s, a.f); }
p conj(p a) { return {a.f, -a.s}; }

p operator + (p a, p b) { return {a.f + b.f, a.s + b.s}; }
p operator - (p a, p b) { return {a.f - b.f, a.s - b.s}; }
p operator * (p a, t b) { return {a.f * b, a.s * b}; }
p operator / (p a, t b) { return {a.f / b, a.s / b}; }

t dot(const p& a, const p& b) { return a.f * b.f + a.s * b.s; }
t dot(const p& c, const p& a, const p& b) { return dot(a - c, b - c); }
t cross(const p& a, const p& b) { return a.f * b.s - a.s * b.f; }
t cross(const p& c, const p& a, const p& b) { return cross(a - c, b - c); }
