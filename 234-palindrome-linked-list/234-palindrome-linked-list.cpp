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
    
    ListNode *getMid(ListNode *head){
        ListNode *slow, *fast;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *rev(ListNode *head){
        ListNode *prev = NULL;
        while(head != NULL){
            // cout << head->val;
            ListNode *temp = head->next;
            // if(temp) cout << temp->val;
            head->next = prev;
            prev = head;
            head = temp;
        }
        ListNode *a = prev;
        // while(a != NULL){
        //     cout << a->val;
        //     a = a->next;
        // }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *h1;
        ListNode *h2;
        ListNode *mid = getMid(head);
        // cout << mid->val;
        h2 = rev(mid);
        while(head != NULL && h2 != NULL){
            // cout << head->val;
            // cout << h2->val << "\n";
            if(head->val != h2->val){
                return false;
            }
            head = head->next;
            h2 = h2->next;
        }
        return true;
    }
};