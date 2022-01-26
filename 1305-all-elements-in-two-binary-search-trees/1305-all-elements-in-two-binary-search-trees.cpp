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
    void pushToVector(vector<int>& vect, TreeNode* node){
        if (node == NULL) return;
        
        pushToVector(vect, node->left);
        vect.push_back(node->val);
        pushToVector(vect, node->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vect1;
        vector<int> vect2;
        vector<int> ans;
        pushToVector(vect1, root1);
        pushToVector(vect2, root2);
        int i = 0; int j = 0;
        int s1 = vect1.size();
        int s2 = vect2.size();
        
        while(i != s1 && j != s2){
            if(vect1[i] <= vect2[j]){
                ans.push_back(vect1[i]);
                i++;
            }
            else {
                ans.push_back(vect2[j]);
                j++;
            }
        }
        
        if (i == s1 && j == s2) return ans;
        if (i == s1) for(i = j; i < s2; i++) ans.push_back(vect2[i]);
        else for (j = i; j < s1; j++) ans.push_back(vect1[j]);
        return ans;
    }
};