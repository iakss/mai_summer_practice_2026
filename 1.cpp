#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t != 0) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 2; i < n + 1; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;

        vector<vector<int>> v(n + 1);
        for (int i = 2; i < n + 1; ++i) {
            v[a[i]].push_back(i);
        }

        stack<int> st;
        vector<int> ord;
        st.push(1);
        int p;
        while (!st.empty()) {
            p = st.top();
            st.pop();
            ord.push_back(p);
            for (auto it = v[p].rbegin(); it != v[p].rend(); ++it) {
                st.push(*it);
            }
        }
        reverse(ord.begin(), ord.end());

        vector<int> b(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            if (s[i - 1] == 'W') {
                b[i] = 1;
            } else {
                b[i] = -1;
            }
        }

        size_t acc = 0;
        for (int i = 0; i < n; ++i) {
            if (ord[i] != 1) {
                b[a[ord[i]]] += b[ord[i]];
            }
            if (b[ord[i]] == 0) {
                ++acc;
            }
        }
        cout << acc << '\n';

        --t;
    }

    return 0;
}
