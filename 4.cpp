#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t) {
        int n, m, k;
        cin >> n >> m >> k;
        string a;
        cin >> a;
        a += 'L';
        int cur = -1;
        int croc = -1;
        bool csa = true;
        for (int i = 0; i < n + 1; ++i) {
            if (a[i] == 'L') {
                if (i - cur <= m || (cur + m > croc && i - (cur + m) <= k)) {
                    k -= max(i - (cur + m), 0);
                    cur = i;
                    croc = -1;
                } else {
                    csa = false;
                    break;
                }
            } else if (a[i] == 'C') {
                croc = i;
            }
        }
        if (csa) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        --t;
    }

    return 0;
}
