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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if(root == NULL) return result;

        vector<int> leftpart = inorderTraversal(root->left);
        result.insert(result.end(),leftpart.begin(), leftpart.end());

        result.push_back(root->val);

        vector<int> rightpart = inorderTraversal(root->right);
        result.insert(result.end(), rightpart.begin(), rightpart.end());

        return result;
    }
};