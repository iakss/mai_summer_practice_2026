#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> gr(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> gr[i][j];
        }
    }
    ll max_mask = (1 << n);
    vector<vector<ll>> dp(max_mask, vector<ll>(n, 0));
    for (ll i = 0; i < n; ++i) {
        dp[1 << i][i] = 1;
    }
    for (ll mask = 2; mask < max_mask; ++mask) {
        for (ll i = 0; i < n; ++i) {
            ll prev_mask = mask ^ (1 << i);
            for (ll j = 0; j < n; ++j) {
                if ((prev_mask & (1 << j)) != 0) {
                    if (gr[i][j]) {
                        dp[mask][i] += dp[prev_mask][j];
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += dp[max_mask - 1][i];
    }
    cout << ans << '\n';

    return 0;
}
