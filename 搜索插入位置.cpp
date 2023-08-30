class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int z = nums.size();
        for(int i = 0 ; i < z ; i++)
        {
            if(target <= nums[i])
            {
                return i;
            }
        }
        return z;
    }
};