#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<pair<int, int>> indexedArr;
    for (int i = 0; i < n; ++i) {
        indexedArr.emplace_back(arr[i], i + 1);
    }

    sort(indexedArr.begin(), indexedArr.end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int target = x - indexedArr[i].first - indexedArr[j].first;
            int left = j + 1, right = n - 1;

            while (left < right) {
                int sum = indexedArr[left].first + indexedArr[right].first;
                if (sum == target) {
                    cout << indexedArr[i].second << " " << indexedArr[j].second << " "
                         << indexedArr[left].second << " " << indexedArr[right].second << endl;
                    return 0;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
