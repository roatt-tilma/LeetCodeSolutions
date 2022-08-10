/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* getNode(ListNode* head, ListNode* tail){
        if(head == tail){
            return NULL;
        }
        
        if(head->next == tail){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        
        ListNode* mid = head;
        ListNode* fast = head;
        
        while(fast != tail && fast->next != tail){
            mid = mid->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = getNode(head, mid);
        root->right = getNode(mid->next, tail);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return getNode(head, NULL);    
    }
};