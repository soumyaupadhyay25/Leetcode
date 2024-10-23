class Solution {
 public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    if (!root) return nullptr;
    
    // Create a queue for level-order traversal
    queue<TreeNode*> q;
    q.push(root);
    
    // Initialize the root value to 0
    root->val = 0;
    
    while (!q.empty()) {
      int n = q.size();  // Number of nodes at the current level
      int levelSum = 0;  // Sum of the current level nodes' original values
      vector<TreeNode*> nodes;  // To store nodes at the current level

      // First pass: Calculate the sum of values at the current level
      for (int i = 0; i < n; ++i) {
        TreeNode* node = q.front();
        q.pop();
        nodes.push_back(node);
        
        // Calculate the sum of children values for the current level
        if (node->left) {
          levelSum += node->left->val;
          q.push(node->left);
        }
        if (node->right) {
          levelSum += node->right->val;
          q.push(node->right);
        }
      }

      // Second pass: Replace values with the sum of cousins' values
      for (TreeNode* node : nodes) {
        int childrenSum = 0;
        
        if (node->left) childrenSum += node->left->val;
        if (node->right) childrenSum += node->right->val;

        // Replace each child's value with the cousins' sum
        if (node->left) node->left->val = levelSum - childrenSum;
        if (node->right) node->right->val = levelSum - childrenSum;
      }
    }

    return root;
  }
};
