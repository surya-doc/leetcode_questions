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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow;
        ListNode *fast;
        ListNode *prev = NULL;
        slow = fast = head;
        int len = 0;
        while(fast != NULL && fast->next != NULL){
            len++;
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(len == 0){
            cout << "*";
            return nullptr;
        }
        prev->next = slow->next;
        return head;
    }
};