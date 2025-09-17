class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* t = head->next;
        while (t) {
            int data = gcd(p->val, t->val);
            ListNode* d = new ListNode(data);
            ListNode* nt = t->next;
            p->next = d;
            d->next = t;
            p = t;
            t = nt;
        }
        return head;
    }
};