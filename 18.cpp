#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    vector<pair<int, int>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0};  

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) { 
                int nextMask = mask | (1 << i);
                if (dp[mask].second + weights[i] <= x) {
                    dp[nextMask] = min(dp[nextMask], {dp[mask].first, dp[mask].second + weights[i]});
                } else {
                    dp[nextMask] = min(dp[nextMask], {dp[mask].first + 1, weights[i]});
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}
