class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> oldToNew;

        Node* curr = head;

        while (curr != nullptr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr != nullptr) {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            curr = curr->next;
        }
        return oldToNew[head];
    }
};
