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
    
    void getQueue(TreeNode* root, queue<TreeNode*>& q){
        
        if(root == NULL) return;
        
        q.push(root);
        getQueue(root->left, q);
        getQueue(root->right, q);
        
    }
    
    
    void flatten(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        getQueue(root, q);
        
        if(q.size() == 1) return;
        
        TreeNode* temp = root;
        
        while(!q.empty()){
            temp->left = NULL;
            temp->right = q.front();
            q.pop();
            temp = temp->right;
        }
    }
};