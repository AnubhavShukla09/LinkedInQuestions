class Solution {
public:
    void dfs(TreeNode* node, double target, int k, deque<int>& dq) {
        if (!node) return;                                // base case: null node
        dfs(node->left, target, k, dq);                   // traverse left subtree (smaller values)
        if (dq.size() < k) {                              // if we still need k elements
            dq.push_back(node->val);                      // directly add current value
        }
        else {
            // check if current value is closer than the worst (front of deque)
            if (abs(dq.front() - target) > abs(node->val - target)) {
                dq.pop_front();                           // remove farthest value
                dq.push_back(node->val);                  // insert current closer value
            }
            else {
                // since inorder traversal is sorted,
                // all further values will be even farther
                return;                                   // prune right subtree
            }
        }
        dfs(node->right, target, k, dq);                  // traverse right subtree (larger values)
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> dq;                                    // stores k closest values (sliding window)
        dfs(root, target, k, dq);                         // start inorder traversal
        return vector<int>(dq.begin(), dq.end());         // convert deque to vector
    }
};
// TC - O(n)      // worst case
// SC - O(k + h)  // deque + recursion stack
