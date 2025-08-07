class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        while (left < right) {
            int sum = sortedNums[left] + sortedNums[right];
            if (sum == target) {
                int idx1, idx2;
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] == sortedNums[left]) {
                        idx1 = i;
                        break;
                    }
                }
                for (int i = nums.size() - 1; i >= 0; i--) {
                    if (nums[i] == sortedNums[right]) {
                        idx2 = i;
                        break;
                    }
                }
                if (idx1 > idx2) {
                    swap(idx1, idx2);
                }
                return {idx1, idx2};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
