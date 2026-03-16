class Solution {
public:
   int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       unordered_map<int, unordered_set<int>> reservedMap; // row -> reserved seats
       int ans = 0;
       // store all reserved seats grouped by row
       for(auto r : reservedSeats) {
           reservedMap[r[0]].insert(r[1]);
       }
       // rows with NO reservations can fit 2 families each
       ans += 2 * (n - reservedMap.size());
       // check each row that has reservations
       for(auto row : reservedMap) {
           auto reserved = row.second; // set of reserved seats in this row
           bool left = true, mid = true, right = true; // 3 possible seat blocks
           // check seats for left (2-5), mid (4-7), right (6-9) blocks
           for(int i = 0; i < 4; i++) {
               if(left && reserved.count(i + 2)) left = false;   // seats 2,3,4,5
               if(mid && reserved.count(i + 4)) mid = false;     // seats 4,5,6,7
               if(right && reserved.count(i + 6)) right = false; // seats 6,7,8,9
           }
           // if both left and right available → 2 families
           if(left && right) ans += 2;
           // if any one block available → 1 family
           else if(left || mid || right) ans++;
       }
       return ans;
   }
};
