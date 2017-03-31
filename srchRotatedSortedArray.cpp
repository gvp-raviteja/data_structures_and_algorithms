/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

class Solution {
public:
    int srch(vector<int>& nums, int target, int low, int high){
        if(low==high){
            if(nums[low]==target)
                return low;
            return -1;
        }
        int mid = (low+high)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[low]<=nums[mid]){
            if(nums[mid]>target && nums[low]<=target)
                return srch(nums, target, low, mid);
            else
                return srch(nums, target, mid+1, high);
        }
        else{
            if(nums[mid]<target && nums[high]>=target){
                return srch(nums, target, mid+1, high);
            }
            else
                return srch(nums, target, low, mid);
        }
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        return srch(nums,target,0,nums.size()-1);
    }
};
