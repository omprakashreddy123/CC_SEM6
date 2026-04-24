#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<ll, ll> events;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        events[l]++;
        events[r + 1]--;
    }

    vector<ll> ans(n + 1, 0);

    ll current_coverage = 0;
    ll prev_coord = events.begin()->first;

    for (auto const& [coord, change] : events) {
        ll distance = coord - prev_coord;

        if (current_coverage > 0 && current_coverage <= n) {
            ans[current_coverage] += distance;
        }

        current_coverage += change;
        prev_coord = coord;
    }

    for (int k = 1; k <= n; k++) {
        cout << ans[k] << (k == n ? "" : " ");
    }
    cout << endl;

    return 0;
}
