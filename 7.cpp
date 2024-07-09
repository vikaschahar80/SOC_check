#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    
    int n = s.size();
    unordered_map<int, int> countMap; 
    countMap[0] = 1;
    
    int currentSum = 0;
    long long int totalCount = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            currentSum++;
        }
        int targetSum = currentSum - k;
        
        if (countMap.find(targetSum) != countMap.end()) {
            totalCount += countMap[targetSum];
        }
        countMap[currentSum]++;
    }

    cout << totalCount << endl;

    return 0;
}
