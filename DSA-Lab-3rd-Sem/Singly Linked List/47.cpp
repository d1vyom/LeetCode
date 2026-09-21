class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            
            curr->next = minNode;
            curr = curr->next;
            
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
        }
        return dummy.next;
    }
};
