class Solution {
public:
    void bt(vector<int>& nums, vector<vector<int>> &ans, vector<int>& v, int start){
      if(start >= nums.size()) return;
      
      for(int i=start; i<nums.size(); i++){
        v.push_back(nums[i]);
        bt(nums, ans, v, i+1);
        //if(v.size()==nums.size()) 
        ans.push_back(v);
        v.pop_back();
      }
    }
  
    vector<vector<int>> subsets(vector<int>& nums) {      
      vector<int> v;
      vector<vector<int>> ans(1,v);
      bt(nums, ans, v, 0);
      return ans;
    }
};
