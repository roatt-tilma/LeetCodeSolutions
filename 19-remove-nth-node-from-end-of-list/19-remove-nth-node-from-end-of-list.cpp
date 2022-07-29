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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        int sz = 1;
        
        while(temp->next != NULL){
            sz++;
            temp = temp->next;
        }
        
        temp = head;
        
        for(int i = 1; i < sz-n ; i++){
            temp = temp->next;
        }
        
        if(temp == head && sz == n){
            head = head->next;
            delete(temp);
        }else{
            ListNode* rem = temp->next;
            temp->next = temp->next->next;
            delete(rem);  
        }
        
        return head;
    }
};