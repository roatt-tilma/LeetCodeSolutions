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
    
    void traverseInOrder(TreeNode* node, vector<int>& inOrder){
        if(node == NULL) return;
        
        traverseInOrder(node->left, inOrder);
        inOrder.push_back(node->val);
        traverseInOrder(node->right, inOrder);
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        
        traverseInOrder(root, inOrder);
        
        return inOrder;
    }
};