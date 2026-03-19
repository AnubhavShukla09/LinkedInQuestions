class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head) return head;                 // edge case: no rotation or empty list
        ListNode* temp = head;
        int nodes = 0;
        while (temp) {                                    // count total number of nodes
            nodes++;
            temp = temp->next;
        }
        k = k % nodes;                                    // reduce k (rotation cycles)
        if (k == 0) return head;                          // no change after modulo
        temp = NULL;                                      // will track node before new head
        ListNode *left = head, *right = head;             // two pointers
        for (int i = 0; i < k - 1; i++) {                 // move right pointer k-1 steps ahead
            right = right->next;
        }
        while (right->next) {                             // move both pointers until right reaches last node
            right = right->next;                          // move right pointer
            temp = left;                                  // track previous of left
            left = left->next;                            // move left pointer
        }
        right->next = head;                               // make list circular
        temp->next = NULL;                                // break link to form new tail
        return left;                                      // left is new head
    }
};

// TC - O(n)
// SC - O(1)
