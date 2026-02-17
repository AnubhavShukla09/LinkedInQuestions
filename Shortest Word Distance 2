class WordDistance {
public:
    // Map: word -> list of indices where it appears in wordsDict
    unordered_map<string, vector<int>> mp;
    // Constructor: preprocess the words list
    WordDistance(vector<string>& wordsDict) {
        // Store positions of each word
        // Example: "coding" -> [3, 10, 15]
        for (int i = 0; i < wordsDict.size(); i++) {
            mp[wordsDict[i]].push_back(i);
        }
    }
    // Return minimum distance between word1 and word2
    int shortest(string word1, string word2) {
        // Get index lists of both words
        auto &v1 = mp[word1];
        auto &v2 = mp[word2];
        int i = 0, j = 0;
        int ans = INT_MAX;
        // Two-pointer technique on sorted index lists
        while (i < v1.size() && j < v2.size()) {
            // Update minimum distance
            ans = min(ans, abs(v1[i] - v2[j]));
            // Move pointer with smaller index
            // because that might reduce difference
            if (v1[i] < v2[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};
