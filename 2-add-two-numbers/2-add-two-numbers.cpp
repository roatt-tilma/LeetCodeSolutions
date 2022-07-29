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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* pAns = ans;
        int carry = 0;
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        while(temp1->next != NULL && temp2->next !=NULL){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        if(temp1->next == NULL){
            while(temp2->next != NULL){
                temp1->next = new ListNode();
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        
        if(temp2->next == NULL){
            while(temp1->next != NULL){
                temp2->next = new ListNode();
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
        }
        
        while(true){
            int s = l1->val + l2->val + carry;
            
            carry = s/10;
            
            ans->val = s%10;
            
            if(l1->next == NULL || l2->next == NULL){
                if(carry == 1) ans->next = new ListNode(carry);
                break;
            } else{
                ans->next = new ListNode();
                ans = ans->next;
            }        
                                    
            l1 = l1->next;
            l2 = l2->next;
        }
        
        return pAns;
    } 
};