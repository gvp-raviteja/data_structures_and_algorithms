/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return INT_MIN;
        int sum[nums.size()]={0};
        int ma = sum[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            sum[i] = max(nums[i],nums[i]+sum[i-1]);
            ma = max(ma,sum[i]);
        }
        return ma;
        
    }
};
