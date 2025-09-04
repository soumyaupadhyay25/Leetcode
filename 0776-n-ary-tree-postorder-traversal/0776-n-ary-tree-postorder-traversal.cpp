/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;

        if(root == NULL) return result;

        for(auto child : root->children){
            vector<int> sub = postorder(child);
            result.insert(result.end(), sub.begin(), sub.end());
        }
        result.push_back(root->val);

        return result;
    }
};