#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < i + 1; ++j) {
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < i + 1; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
        }
    }
    ll ans = 0;
    for (int j = 1; j < n + 1; ++j) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << '\n';

    return 0;
}
