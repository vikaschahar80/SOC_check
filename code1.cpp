#include <iostream>
#include <cmath>
using namespace std;
int numberofdiv(int n) {
    if (n == 1) return 1;
    int num = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i) {
                num++; // Perfect square divisor, count only once
            } else {
                num += 2; // Count both divisors
            }
        }
    }
    return num;
}
int main() {
    // Write C++ code here
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        cout<<numberofdiv(n)<<endl;
    }
}