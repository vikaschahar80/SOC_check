class Solution {
private:
    int findLeftmost(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int leftmost = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] >= target) {
                if (nums[mid] == target) {
                    leftmost = mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return leftmost;
    }
    
    int findRightmost(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int rightmost = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] <= target) {
                if (nums[mid] == target) {
                    rightmost = mid;
                }
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return rightmost;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeftmost(nums, target);
        int right = findRightmost(nums, target);
        
        if (left == -1 || right == -1) {
            return {-1, -1};
        }
        
        return {left, right};
    }
};
