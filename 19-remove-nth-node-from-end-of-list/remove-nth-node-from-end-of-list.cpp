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
        ListNode* a = new ListNode(0);
        a->next = head;
        ListNode* f = a;
        ListNode* s = a;
        for(int i=0;i<=n;i++){
            f=f->next;
        }
        while(f!=NULL){
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return a->next;
    }
};