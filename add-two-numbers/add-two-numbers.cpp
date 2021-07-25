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
        int a = 0;
        ListNode* an;
        an = new ListNode();
        ListNode* ans = an;
        
        while(l1 && l2){
            a += l1->val + l2->val;
            an->val = a%10;
            if(l1->next || l2->next){
                an->next = new ListNode();
                an = an->next;   
            }
            l1 = l1->next;
            l2 = l2->next;
            if(a >= 10) a = 1;
            else a = 0;
        }
        
        while(l1){
            a += l1->val;
            an->val = a%10;
            if(l1->next){
                an->next = new ListNode();
                an = an->next;   
            }
            l1 = l1->next;
            if(a >= 10) a = 1;
            else a = 0;
        }
        
        while(l2){
            a += l2->val;
            an->val = a%10;
            if(l2->next){
                an->next = new ListNode();
                an = an->next;   
            }
            l2 = l2->next;
            if(a >= 10) a = 1;
            else a = 0;
        }
        
        if (a == 1){
            an->next = new ListNode();
            an = an->next;
            an->val = 1;
        } 
        
        return ans;
    } 
};