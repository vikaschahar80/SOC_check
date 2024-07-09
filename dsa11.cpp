#include<iostream>
#include<cmath>
using namespace std;
const long long m = 1000000007;

long long power(long long a, long long b, long long m) {
    if (a == 0 && b == 0) return 1;
    long long result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1) 
            result = (result * a) % m;
        b = b >> 1; 
        a = (a * a) % m; 
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        cout << power(a, b, m) << endl;
    }
    return 0;
}