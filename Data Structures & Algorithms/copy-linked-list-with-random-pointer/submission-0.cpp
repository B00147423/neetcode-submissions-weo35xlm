/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node*, Node*> m;

        // First pass: copy all nodes and put in map
        Node* cur = head;
        while (cur) {
            m[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Second pass: assign .next and .random
        cur = head;
        while (cur) {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }

        return m[head];


    }
};
