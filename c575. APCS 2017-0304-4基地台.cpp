#include <bits/stdc++.h>
using namespace std;

vector<int> mp;
int n, k;

bool check(int mid) {
    int now = mp[0] + mid, cnt = 1;
    for (int i : mp) {
        if (i <= now) continue;
        cnt++;
        now = i + mid;
    }
    return (cnt <= k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    mp.resize(n);
    for (int i = 0; i < n; i++) cin >> mp[i];

    sort(mp.begin(), mp.end());

    int l = 0, r = mp[n - 1];
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << r << "\n";
    return 0;
}