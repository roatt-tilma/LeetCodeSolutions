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
        
        for(int i = 0; i < sz-n ; i++){
            prev = temp;
            temp = temp->next;
        }
        
        if(prev == NULL) head = head->next;
        
        if(prev != NULL)prev->next = temp->next;
        
        return head;
    }
};