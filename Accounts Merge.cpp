class Solution {
private:
    vector<int> par, rank;  // DSU arrays: parent + rank (almost O(1) per op due to path compression)
    int findPar(int i) {
        if (i == par[i]) return i;                  // If node is its own parent → root found
        return par[i] = findPar(par[i]);            // Path compression: flatten tree
    }  
    void unionByRank(int i, int j) {
        int x = findPar(i), y = findPar(j);         // Find ultimate parents
        if (x == y) return;                         // Already in same component
        if (rank[x] > rank[y]) {
            par[y] = x;                             // Attach smaller tree under larger tree
        } else if (rank[y] > rank[x]) {
            par[x] = y;
        } else {
            par[x] = y;                             // If equal rank → attach arbitrarily
            rank[y]++;                              // Increase rank of new root
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mailToNode;      // Map each email → account index
        int n = accounts.size();
        par.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {               // Initialize DSU
            par[i] = i;                             // Each node is its own parent initially
        }
        // Step 1: Build DSU by connecting accounts with same emails
        for (int i = 0; i < n; i++) {               // Iterate all accounts
            for (int j = 1; j < accounts[i].size(); j++) { // Skip name at index 0
                string mail = accounts[i][j];
                if (!mailToNode.count(mail)) {
                    mailToNode[mail] = i;           // First time seeing this email → map it
                } else {
                    unionByRank(i, mailToNode[mail]); // Same email → merge accounts
                }
            }
        }
        // Step 2: Group emails by their ultimate parent
        vector<vector<string>> mails(n);            // mails[i] stores emails belonging to parent i
        for (auto &mtn : mailToNode) {
            int parent = findPar(mtn.second);       // Find representative parent
            string mail = mtn.first;
            mails[parent].push_back(mail);          // Group email under parent
        }
        // Step 3: Build final answer
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mails[i].empty()) continue;         // Skip if no emails for this parent
            vector<string> temp;
            temp.push_back(accounts[i][0]);         // Add account name (any one from group)
            sort(begin(mails[i]), end(mails[i]));   // Sort emails lexicographically
            for (auto &m : mails[i]) {
                temp.push_back(m);                 // Add sorted emails
            }
            ans.push_back(temp);                   // Add merged account
        }
        return ans;                                // Final merged accounts
    }
};

// Time Complexity: O(N + M + M log M)
// N = number of accounts
// M = total number of emails

// Space Complexity: O(N + M)
