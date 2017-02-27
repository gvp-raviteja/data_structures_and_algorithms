/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of 
all the node values formed by the subtree rooted at that node (including the node itself). 
So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,int> hash;
    int findf(TreeNode *root){
        int sum = 0;
        if(root){
            sum += findf(root->left);
            sum += findf(root->right);
            sum += root->val;
            if(hash.find(sum)!=hash.end()){
                hash[sum] +=1; 
            }
            else
                hash[sum] = 1;
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        findf(root);
        vector<int> out;
        map<int,vector<int>> s;
        for (map<int,int>::iterator it=hash.begin(); it!=hash.end(); ++it){
            if(s.find(it->second)!=s.end())
                s[it->second].push_back(it->first);
            else{
                vector<int> a ;
                a.push_back(it->first);
                s[it->second] = a;
            }
        }
        if(s.empty())
            return out;
        map<int,vector<int>>::reverse_iterator it=s.rbegin();
        return it->second;
    }
};
