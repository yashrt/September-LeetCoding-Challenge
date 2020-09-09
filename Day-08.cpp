/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getSum(TreeNode* root,int temp, int& res)
    {
        if(root)
        {
            if(root->left==NULL && root->right==NULL)
                res += 2*temp+root->val;
            else
            {
                getSum(root->left, 2*temp+root->val, res);
                getSum(root->right, 2*temp+root->val, res);
            }
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        getSum(root, 0, res);
        return res;
    }
};
