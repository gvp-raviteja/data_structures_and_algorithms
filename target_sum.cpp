/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.
*/

// top-down approach
class Solution {
public:
    map<pair<int,int>,int> hash;
    int findt(vector<int>& nums, int S,int i){
        if(hash.find(make_pair(S,i))!=hash.end())
            return hash[make_pair(S,i)];
        if(i==nums.size()){
            if(S==0)
                return 1;
            else
                return 0;
        }
        hash[make_pair(S,i)] = findt(nums,S-nums[i],i+1) + findt(nums,S+nums[i],i+1);
        return hash[make_pair(S,i)];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return findt(nums,S,0);
    }
};

// TODO : bottom-up approach
