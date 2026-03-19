class Solution {
public:
    bool check(vector<int>& a, vector<int>& m, vector<int>& x){ // function to check if 3 points are collinear
        // check for (a,b), (m,n), and (x,y) using cross multiplication
        // (n−b)(x−m) = (y−n)(m−a)
        int l, r;                                              // variables to store left and right side of equation
        l = (m[1] - a[1]) * (x[0] - m[0]);                     // (n-b)*(x-m)
        r = (x[1] - m[1]) * (m[0] - a[0]);                     // (y-n)*(m-a)
        return l == r;                                         // return true if both sides are equal (collinear)
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();                                 // total number of points
        if(n < 3) return n;                                    // if less than 3 points, all are collinear   
        int ans = 0;                                           // store maximum points on a line
        for(int i = 0; i < n; i++){                            // pick first point
            for(int j = i + 1; j < n; j++){                    // pick second point
                int count = 0;                                 // count points on same line
                // ensure points i and j are not identical
                if((points[i][0] != points[j][0]) || (points[i][1] != points[j][1])){
                    for(int k = 0; k < n; k++){                // check all points with line formed by i and j
                        count += check(points[i], points[j], points[k]); // increment if collinear
                    }
                }
                ans = max(ans, count);                         // update maximum count
            }
        }
        return ans;                                            // return final answer
    }
};

class Solution {
public:
    int gcd(int a, int b){                                     // function to compute gcd
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();                                 // total number of points
        if(n < 3) return n;                                    // if less than 3, all are collinear   
        int ans = 0;                                           // store maximum points
        for(int i = 0; i < n; i++){                            // fix one point
            unordered_map<string, int> mp;                     // map to store slope frequency
            int duplicates = 1;                                // count duplicates of point i
            int localMax = 0;                                  // max points for current i
            for(int j = i + 1; j < n; j++){                    // compare with all other points
                int dx = points[j][0] - points[i][0];          // difference in x
                int dy = points[j][1] - points[i][1];          // difference in y
                if(dx == 0 && dy == 0){                       // duplicate point
                    duplicates++;
                    continue;
                }
                int g = gcd(dx, dy);                          // reduce slope
                dx /= g;
                dy /= g;
                string key = to_string(dx) + "_" + to_string(dy); // unique slope key
                mp[key]++;                                     // increment slope count
                localMax = max(localMax, mp[key]);            // update local max
            }
            ans = max(ans, localMax + duplicates);            // include duplicates
        }
        return ans;                                            // final answer
    }
};
