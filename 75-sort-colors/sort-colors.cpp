class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
       for (int i = 1; i < n; ++i) {
            int key = nums[i];
            int j = i - 1;

            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
            nums[j + 1] = key;
        } 
        for (int i = 0;i<n;i++){
        cout<<nums[i];
    }
    }
};