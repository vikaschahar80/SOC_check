class Solution {
private:
    void solve(int i,int n,vector<int>& dp,vector<int>& nums){
        if(i<0){
            return;
        }
       if(i==n-1){
        dp[i] = 0;
       }
       else if(nums[i]>nums[i+1]){
            dp[i] = dp[i+1]+1;
        }
       else {
            int count = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    count++;
                }
            }
            dp[i] = count;
        }
       solve(i-1,n,dp,nums);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        solve(n-1,n,dp,nums);
        return dp;
    }
};
