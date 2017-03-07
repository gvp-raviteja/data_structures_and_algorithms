/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
// Binary search solution n(logn)
class Solution {
public:
    int dup(vector<int> nums, int low,int high){
        int mid = (low+high)/2, count=0;
        if(low>=high)
            return low;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid)
                count++;
        }
        if(count<=mid)
            return dup(nums,mid+1,high);
        else
            return dup(nums,low,mid);
    }
    
    int findDuplicate(vector<int>& nums) {
        int high = nums.size()-1;
        int low = 1;
        return dup(nums,low,high);
    }
};

// TODO: can be solved in linear time similar to loop in linked list
