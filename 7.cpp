#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t > 0) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        unordered_map<ll, ll> b;
        for (ll i = 0; i < m; ++i) {
            ll e;
            cin >> e;
            ++b[e];
        }
        unordered_map<ll, ll> s;
        ll cnt = 0;
        for (ll i = 0; i < m; ++i) {
            if (b.contains(a[i])) {
                ++s[a[i]];
                if (s[a[i]] <= b[a[i]]) {
                    ++cnt;
                }
            }
        }
        ll ans = cnt >= k ? 1 : 0;
        for (ll i = m; i < n; ++i) {
            if (s.contains(a[i - m])) {
                --s[a[i - m]];
                if (s[a[i - m]] < b[a[i - m]]) {
                    --cnt;
                }
            }
            if (b.contains(a[i])) {
                ++s[a[i]];
                if (s[a[i]] <= b[a[i]]) {
                    ++cnt;
                }
            }
            if (cnt >= k) {
                ++ans;
            }
        }
        cout << ans << '\n';

        --t;
    }
    return 0;
}
