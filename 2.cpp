#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void z_func(string& s, vector<int>& z) {
    int n = s.size();
    z.resize(n, 0);
    z[0] = n;
    int l, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}
int main() {
    string s;
    cin >> s;
    int n = s.size();
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string z_str = s + '#' + rev_s;
    int m = 2 * n + 1;
    vector<int> z;
    z_func(z_str, z);
    int ans;
    for (int i = n + 1; i < m; ++i) {
        if (i - (n + 1) + z[i] == n) {
            ans = z[i];
            break;
        }
    }
    cout << ans;

    return 0;
}
