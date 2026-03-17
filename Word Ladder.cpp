class Solution {
private:
    unordered_set<string> wordset;     // Stores all valid words for O(1) lookup
    string endWord;                   // Target word we want to reach
    int bfs(string s) {
        queue<string> q;              // Queue for BFS traversal
        q.push(s);                   // Start from beginWord
        int level = 1;               // Number of transformations (distance)
        while (!q.empty()) {         
            int sz = q.size();       // Number of nodes at current level
            for (int i = 0; i < sz; i++) {
                string curr = q.front(); // Current word
                q.pop();
                if (curr == endWord) {   // If we reached target
                    return level;        // Return number of steps
                }
                for (int j = 0; j < curr.size(); j++) { // Try changing each character
                    char ch = curr[j];                 // Store original character
                    for (char k = 'a'; k <= 'z'; k++) { // Try all possible letters
                        curr[j] = k;                   // Replace character
                        if (wordset.count(curr)) {     // If new word is valid
                            q.push(curr);              // Add to BFS queue
                            wordset.erase(curr);       // Mark as visited (avoid revisiting)
                        }
                    }
                    curr[j] = ch; // Restore original character before next iteration
                }
            }
            level++; // Move to next transformation level
        }
        return 0; // If no transformation sequence found
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string &word : wordList) {
            wordset.insert(word);    // Insert all words into set
        }
        this->endWord = endWord;     // Store target word
        if (!wordset.count(endWord)) return 0; // If endWord not in list → impossible
        return bfs(beginWord);       // Start BFS from beginWord
    }
};
