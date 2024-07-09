#include <iostream>
#include <vector>
using namespace std;
 
long long number_in_spiral(long long y, long long x) {
    if (y > x) {
        if (y % 2 == 0) {
            return y * y - x + 1;
        } else {
            return (y - 1) * (y - 1) + x;
        }
    } else {
        if (x % 2 == 0) {
            return (x - 1) * (x - 1) + y;
        } else {
            return x * x - y + 1;
        }
    }
}
 
int main() {
    int t;
    cin >> t;
    vector<long long> results(t);
    for (int i = 0; i < t; ++i) {
        long long y, x;
        cin >> y >> x;
        results[i] = number_in_spiral(y, x);
    }
 
    for (long long result : results) {
        cout << result << endl;
    }
 
    return 0;
}
