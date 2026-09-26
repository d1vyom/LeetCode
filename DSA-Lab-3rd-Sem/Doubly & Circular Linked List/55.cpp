class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        
        while (curr != nullptr) {
            
            if (curr->child != nullptr) {
                Node* nextNode = curr->next;
                Node* childHead = curr->child;
                
                Node* childTail = childHead;
                while (childTail->next != nullptr) {
                    childTail = childTail->next;
                }
                
                curr->next = childHead;
                childHead->prev = curr;
                
                curr->child = nullptr;
                
                childTail->next = nextNode;
                if (nextNode != nullptr) {
                    nextNode->prev = childTail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
