// time comp - o(n+m)
//recurively merging lits

class Solution {
  public:
  Node *merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    
    // Ensure the next pointer is always null in the flattened list
    result->next = NULL; 
    return result;
}

    Node *flatten(Node *root) {
        
        if (!root || !root->next) 
        {
            return root;
        }
            root->next = flatten(root->next);
            root = merge(root, root->next);
            return root;
        }
    };

    //optimal solution - O(KlogN)
    // using min heap
    #include <queue>
#include <vector>

// Comparator for the Min-Heap to compare Node values
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* flatten(Node* root) {
    if (!root) return nullptr;

    // Min-Heap to store the heads of the lists
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Step 1: Push the head of each vertical list into the priority queue
    Node* temp = root;
    while (temp != nullptr) {
        pq.push(temp);
        temp = temp->next;
    }

    Node* dummy = new Node(); // Dummy node to simplify building the result
    Node* res = dummy;

    // Step 2: Extract the minimum and push its 'bottom' child
    while (!pq.empty()) {
        Node* curr = pq.top();
        pq.pop();

        // Add curr to our flattened list using the 'bottom' pointer
        res->bottom = curr;
        res = res->bottom;

        // If there's a node below, push it into the heap
        if (curr->bottom) {
            pq.push(curr->bottom);
        }
        
        // Ensure flattened nodes don't point to original 'next' lists
        curr->next = nullptr;
    }

    return dummy->bottom;
}
