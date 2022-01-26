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
    void pushToVector(vector<int>& ans, TreeNode* node){
        if (node == NULL) return;
        
        pushToVector(ans, node->left);
        ans.push_back(node->val);
        pushToVector(ans, node->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        pushToVector(ans, root1);
        pushToVector(ans, root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};