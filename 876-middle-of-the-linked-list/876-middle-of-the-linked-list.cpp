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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        ListNode* ans = slow;
        
        if(ans == NULL) return ans;
        
        while(true){
    
            if(fast->next == NULL){
                ans = slow;
                break;
            }
            
            if(fast->next->next == NULL){
                ans = slow->next;
                break;
            } 
            
            slow = slow->next;
            fast = fast->next->next; 
        }
        
        return ans;
    }
};