class NumArray {
vector arr;
int sum;
public:
NumArray(vector& nums) {
arr = nums;
sum = accumulate(arr.begin(),arr.end(),0);
}

void update(int index, int val) {
    sum -= arr[index];
    arr[index] = val;
    sum += arr[index];
}

int sumRange(int left, int right) {
    int ans = sum ;
    for(int i = 0; i<left;i++){
    ans -= arr[i];
    } 
    for(int i = right+1; i<arr.size();i++){
    ans -= arr[i];
    } 
    return ans;
}
};
