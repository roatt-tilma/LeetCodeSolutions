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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL) return head;
        
        ListNode* postNode = NULL;
        ListNode* preNode = NULL;
        
        ListNode* temp = head;
        
        int flag = 0;
        
        
        if(temp->val >= x){
            postNode = head;
            flag = 1;
        }
        
        while(temp->next != NULL){
            
            ListNode* tempPre = temp;
            temp = temp->next;
            
            if(temp->val >= x && flag == 0){
                postNode = temp;
                preNode = tempPre;
                flag = 1;
            } 
            
            if(temp->val < x && flag == 1){   
                tempPre->next = temp->next;
                temp->next = postNode;                    

                if(preNode == NULL){
                    preNode = temp;
                    head = preNode;
                    continue;
                }

                preNode->next = temp;
                preNode = temp;
                temp = tempPre;
            }
        }
        
        return head;
    }
};