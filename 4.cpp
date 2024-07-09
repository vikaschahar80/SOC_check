#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    for (int x = 0; x <= c / a; ++x) {
        int remaining_damage = c - a * x;
        if (remaining_damage % b == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
