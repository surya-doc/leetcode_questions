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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* q = head;
        int l = 0;
        while(q != nullptr){
            if(l < k-1){
                p = p->next;
            }
            q = q->next;
            l++;
        }
        q = head;
        int i = 0;
        while(i < l-k){
            q = q->next;
            i++;
        }
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
        cout << q->val;
        return head;
    }
};