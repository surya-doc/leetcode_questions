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
    
    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        ListNode* prev = NULL;
        ListNode* temp = head;
        int l = len-n;
        int i = 0;
        if(len == 1 && n == 1){
            return NULL;
        }
        else if(l == 0){
            return head->next;
        }
        else{
        while(i < l){
            prev = temp;
            temp = temp->next;
            i++;
        }  
        }
        prev->next = temp->next;
        return head;
    }
};