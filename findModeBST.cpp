/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
    int prev=INT_MIN;
    int max_count = 1;
    int count = 0;
    vector<int> output;
    void findM(TreeNode* root) {
        if(root){
            findM(root->left);
            if(prev!=root->val){
                if(count>max_count){
                    max_count = count;
                    output.clear();
                    output.push_back(prev);
                }
                else if(count==max_count)
                    output.push_back(prev);
                prev = root->val;
                count = 1;
            }
            else{
                count++;
            }
            findM(root->right);
        }
    }
    vector<int> findMode(TreeNode* root){
        findM(root);
        if(count>max_count){
            output.clear();
            output.push_back(prev);
        }
        else if(count == max_count){
            output.push_back(prev);
        }
        return output;
    }
    
};
