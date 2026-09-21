class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int n = 0;
        ListNode* curr = head;

        while (curr) {
            n++;
            curr = curr->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (n >= k) {
            ListNode* groupStart = prevGroupEnd->next;
            curr = groupStart;
            ListNode* prev = prevGroupEnd;

            for (int i = 0; i < k; ++i) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            prevGroupEnd->next = prev;
            groupStart->next = curr;
            prevGroupEnd = groupStart;

            n -= k;
        }
        return dummy.next;
    }
};
