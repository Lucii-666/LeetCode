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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head; 
        }

        
        ListNode* current = head;
        int length = 1;  
        while (current->next) {
            current = current->next;
            length++;
        }

        k = k % length;  
        if (k == 0) {
            return head;  
        }

        current = head;
        for (int i = 0; i < length - k - 1; i++) {
            current = current->next;
        }

        ListNode* newHead = current->next;  // This will be the new head
        current->next = nullptr;  // Break the link to make it the new tail

        ListNode* last = newHead;
        while (last->next) {
            last = last->next;
        }
        last->next = head;  // Connect the last node to the old head

       
        return newHead;
    }
};
