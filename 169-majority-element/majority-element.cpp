class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int c;

        for (int num : nums) {
            if (count == 0) {
                c = num;
            }
            count += (num == c) ? 1 : -1;
        }

        return c;
    }


};