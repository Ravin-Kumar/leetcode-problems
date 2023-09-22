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
        
        // checks for any empty lists
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* list1_p = list1;
        ListNode* list2_p = list2;
        ListNode* head;
        ListNode* prev_node_p;

        // setting head and identifying first Node
        if (list1_p->val < list2_p->val) {
            prev_node_p = list1_p;
            head = list1_p;
            list1_p = list1_p->next;
        }
        else {
            prev_node_p = list2_p;
            head = list2_p;
            list2_p = list2_p->next;
        }
        
        while ((list1_p != nullptr) & (list2_p != nullptr)) {

            if (list1_p->val < list2_p->val) {
                prev_node_p->next = list1_p;
                prev_node_p = list1_p;
                list1_p = list1_p->next;
            }
            else {
                prev_node_p->next = list2_p;
                prev_node_p = list2_p;
                list2_p = list2_p->next;
            }
        }

        if (list1_p == nullptr) {
            prev_node_p->next = list2_p;
        }
        else {
            prev_node_p->next = list1_p;
        }

        return head;
    }
};