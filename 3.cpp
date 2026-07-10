#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            int temp = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] += max(dp[i - 1][j - 1], temp);
        }
    }
    cout << dp[n][m] << '\n';

    return 0;
}
