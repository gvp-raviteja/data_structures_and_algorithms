/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

// Approach 1, sort one array and binary search each element of second array in the first
class Solution {
public:
    bool search(vector<int> &nums1, int a){
        int low,high;
        int mid;
        low = 0;
        high = nums1.size();
        while(low<=high){
            mid = (low+high)/2;
            if(nums1[mid]==a)
                return true;
            else if(nums1[mid]<a)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        vector<int> output;
        if(nums1.size()>0){
            sort(nums1.begin(),nums1.end());
            for(int i=0;i<nums2.size();i++){
                if(hash.find(nums2[i])==hash.end() && search(nums1,nums2[i])){
                    hash.insert(nums2[i]);
                }
            }
            copy(hash.begin(), hash.end(), back_inserter(output));
        }
        return output;
    }
};

// Approach 2, make unordered_set out of array1 and search elements of array2 in unordered_set
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(),nums1.end());
        vector<int> output;
        if(nums1.size()>0){
            for(int i=0;i<nums2.size();i++){
                if(hash.find(nums2[i])!=hash.end()){
                    hash.erase(nums2[i]);
                    output.push_back(nums2[i]);
                }
            }
        }
        return output;
    }
};
