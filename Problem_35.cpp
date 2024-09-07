class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int l=0;
        int h=nums.size()-1;
        int mid=(l+h)/2;
        while(l<=h){
            if(nums[l]==target){
                return l;
            }
            if(nums[h]==target){
                return h;
            }
            if(nums[mid]<target){
                l=mid+1;
                mid=(l+h)/2;
            }
            if(nums[mid]>target){
                 h=mid-1;
                mid=(l+h)/2;
            }
            if(nums[mid]==target){
               return mid;
            }
  
        }
        if(target<nums[mid]){
            return l;
        }
        if(target>nums[mid]){
            return l;
        }
        return 0;

    }
};