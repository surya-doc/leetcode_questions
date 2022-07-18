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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1, *p2;
        p1 = list1;
        p2 = list2;
        if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }
        ListNode* head = list1;
        if(list1->val > list2->val){
            head = list2;
            list2 = list2->next;
        }
        else{
            list1 = list1->next;
        }
        ListNode* curnt = head;
        
        while(list1 && list2){
            cout << p1->val << p2->val << " ";
            if(list1->val <= list2->val){
                curnt->next = list1;
                list1 = list1->next;
            }
            else{
                curnt->next = list2;
                list2 = list2->next;
            }
            curnt = curnt->next;
        }
        if(list1){
            curnt->next = list1;
        }
        else{
            curnt->next = list2;
        }
        return head;
    }
};