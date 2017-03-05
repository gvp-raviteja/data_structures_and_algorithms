// You need to find the largest value in each row of a binary tree.

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
    vector<int> largestValues(TreeNode* root) {
        TreeNode* temp;
        queue<TreeNode*> q;
        queue<TreeNode*> q1;
        vector<int> output;
        int max = INT_MIN;
        if(root){
            q.push(root);
        }
        while(!q.empty() || !q1.empty()){
            if(!q.empty()){
                max = INT_MIN;
                while(!q.empty()){
                    temp = q.front();
                    if(temp->val > max)
                        max = temp->val;
                    if(temp->left!=NULL)
                        q1.push(temp->left);
                    if(temp->right!=NULL)
                        q1.push(temp->right);
                    q.pop();
                }
                output.push_back(max);
            }
            if(!q1.empty()){
                max = INT_MIN;
                while(!q1.empty()){
                    temp = q1.front();
                    //cout << temp->val;
                    if(temp->val > max)
                        max = temp->val;
                    if(temp->left!=NULL)
                        q.push(temp->left);
                    if(temp->right!=NULL)
                        q.push(temp->right);
                    q1.pop();
                }
                output.push_back(max);
            }
        }
        return output;
    }
};
