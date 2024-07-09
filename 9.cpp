#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>
using namespace std;
 
class SlidingWindowMedian {
public:
    SlidingWindowMedian(int k) : k(k) {}
    
    void addNum(int num) {
        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
        } else {
            right.insert(num);
        }
        balanceHeaps();
    }
    
    void removeNum(int num) {
        if (left.find(num) != left.end()) {
            left.erase(left.find(num));
        } else {
            right.erase(right.find(num));
        }
        balanceHeaps();
    }
    
    int findMedian() {
        return *left.rbegin();
    }
    
private:
    multiset<int> left, right;
    int k;
    
    void balanceHeaps() {
        if (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            left.erase(--left.end());
        } else if (left.size() < right.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
};
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
 
    SlidingWindowMedian swm(k);
    vector<int> result;
 
    for (int i = 0; i < k; ++i) {
        swm.addNum(arr[i]);
    }
    result.push_back(swm.findMedian());
 
    for (int i = k; i < n; ++i) {
        swm.addNum(arr[i]);
        swm.removeNum(arr[i - k]);
        result.push_back(swm.findMedian());
    }
 
    for (int median : result) {
        cout << median << " ";
    }
    cout << endl;
 
    return 0;
}
