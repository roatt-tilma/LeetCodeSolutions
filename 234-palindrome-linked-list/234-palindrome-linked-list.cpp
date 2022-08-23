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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        // 1 3 5 7
        // 1 2 3 4
        
        // 1 3 5 7
        // 1 2 3 4
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = head;
        
        stack<int> st;
        
        while(slow != NULL){
            st.push(slow->val);
            slow = slow->next;
        }
        
        while(!st.empty()){
            if(st.top() != fast->val) return false;
            st.pop();
            fast = fast->next;
        }
        
        return true;
    }
};